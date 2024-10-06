
#include "ComputerStore.h"


//PUBLIC-----------------------------------------------------------------------------


ComputerStore::ComputerStore() {
	Null();
}
ComputerStore::ComputerStore(const char* name, const ComputerPart* products, const size_t* availability, size_t productCount, double revenue, const char* workH) {
	Null();
	
	setRevenue(revenue);
	setWorkHours(workH);
	setStoreName(name);
	checkAndChangeIsObjInit();
	
	if (productCount == 0 || !products || !availability)
		return;
	
	replaceProducts(products, availability, productCount);
}
ComputerStore::ComputerStore(const ComputerStore& other) {
	Null();
	*this = other;
}
ComputerStore& ComputerStore::operator=(const ComputerStore& other) {
	if (this != &other) {
		delete[] storeName;
		delete[] products;
		delete[] availability;
		Null();

		IS_OBJ_INIT = other.IS_OBJ_INIT;
		revenue = other.revenue;
		strcpy(workHours, other.workHours);

		if (other.storeName) {
			storeName = new char[strlen(other.storeName) + 1];
			strcpy(storeName, other.storeName);
		}
		
		productCount = other.productCount;
		if (productCount) {
			products = new ComputerPart[productCount];
			availability = new size_t[productCount];

			copyProductsAndAvailabitity(other.products, products, other.availability, availability, productCount);
		}
	}

	return *this;
}
ComputerStore::~ComputerStore() {
	delete[] storeName;
	delete[] products;
	delete[] availability;
}


bool ComputerStore::addProduct(const ComputerPart& CP, size_t av) {
	if (!CP.isObjInit())	// Don't add unititialized products.
		return false;

	++productCount;
	ComputerPart* newProdArr = new ComputerPart[productCount];
	size_t* newAvArr = new size_t[productCount];

	// Copy products to the bigger array.
	copyProductsAndAvailabitity(products, newProdArr, availability, newAvArr, productCount - 1);
	
	newProdArr[productCount - 1].setComputerPartOnce(CP);
	newAvArr[productCount - 1] = av;

	deleteProductsAndAvailability();

	products = newProdArr;
	availability = newAvArr;

	return true;
}
bool ComputerStore::removeProduct(const ComputerPart& CP) {
	size_t removeIndex = 0;
	for (; removeIndex < productCount; ++removeIndex) {
		if (CP == products[removeIndex])		
			break;
	}

	if (removeIndex >= productCount)	// No maching product.
		return false;

	--productCount;
	if (productCount == 0) {				// If removing the last and only product.
		deleteProductsAndAvailability();
		return true;
	}

	ComputerPart* CPtemp = new ComputerPart[productCount];
	size_t* AVtemp = new size_t[productCount];
	
	// Copy products before 'i'.
	copyProductsAndAvailabitity(products, CPtemp, availability, AVtemp, removeIndex);

	// Copy after 'i'.
	for (; removeIndex < productCount; ++removeIndex) {
		CPtemp[removeIndex].setComputerPartOnce(products[removeIndex + 1]);
		AVtemp[removeIndex] = availability[removeIndex + 1];
	}

	deleteProductsAndAvailability();
	products = CPtemp;
	availability = AVtemp;

	return true;
}
bool ComputerStore::findProduct(const char* type, const char* brand) const {
	for (size_t i = 0; i < productCount; ++i)
		if (!strcmp(type, products[i].getType()) && !strcmp(brand, products[i].getBrand())) 
			return true;	// Found a maching product.
		
	return false;	// Did not find maching product.
}
void ComputerStore::replaceProducts(const ComputerPart* products, const size_t* availability, size_t productCount) {
	deleteProductsAndAvailability();
	this->productCount = 0;

	if (productCount == 0) {
		this->productCount = 0;
		return;
	}

	// Count the initialized objects.
	size_t realProdCount = 0;
	for (size_t i = 0; i < productCount; ++i) {
		if (products[i].isObjInit())
			++realProdCount;
	}

	if (realProdCount == 0)
		return;

	this->productCount = realProdCount;
	this->products = new ComputerPart[realProdCount];
	this->availability = new size_t[realProdCount];

	// Don't save the unitinialized objects.
	for (size_t i = 0, k = 0; i < productCount; ++i) {
		if (products[i].isObjInit()) {
			this->products[k].setComputerPartOnce(products[i]);
			this->availability[k] = availability[i];
			++k;
		}
	}
}


bool ComputerStore::setRevenue(double revenue) {
	if (revenue < 0.0)
		return false;

	this->revenue = revenue;
	checkAndChangeIsObjInit();

	return true;
}
bool ComputerStore::setStoreName(const char* newName) {
	if (!newName)
		return 0;

	size_t len = strlen(newName);
	if (len == 0)		// Don't accept empty names.
		return 0;

	delete[] storeName;
	storeName = new char[len + 1];
	strcpy(storeName, newName);

	checkAndChangeIsObjInit();

	return 1;
}
bool ComputerStore::setWorkHours(const char* workH) {
	if (!workH || strlen(workH) != 11 || workH[5] != '-')
		return false;
	
	int from = isTimeValid(workH);
	int to = isTimeValid(workH + 6);

	if (from < 0 || to < 0)
		return false;

	if (from <= to)
		strcpy(workHours, workH);
	else {
		// Switch the earlier time to be first
		char temp[12];
		strcpy(temp, workH);
		temp[5] = 0;
		strcpy(workHours, workH + 6);
		strcpy(workHours + 6, temp);
		workHours[5] = '-';
	}

	checkAndChangeIsObjInit();

	return true;
}


const ComputerPart* ComputerStore::getProducts() const { return products; }
const size_t* ComputerStore::getAvailability() const { return availability; }
const char* ComputerStore::getWorkHours() const { return workHours; }
const char* ComputerStore::getStoreName() const { return storeName; }
double ComputerStore::getRevenue() const { return revenue; }
size_t ComputerStore::getProductCount() const { return productCount; }
bool ComputerStore::isObjInit() const { return IS_OBJ_INIT; }

void ComputerStore::print() {
	if (storeName)
		std::cout << storeName;
	else 
		std::cout << "UNDEFINED";

	std::cout << std::endl;

	if (*workHours)
		std::cout << workHours;
	else
		std::cout << "UNDEFINED";

	std::cout << std::endl << productCount << "\n[\n";
	for (size_t i = 0; i < productCount; ++i) {
		std::cout << "    ";
		products[i].print();
		std::cout << " " << availability[i] << "\n";
	}

	std::cout << "]\n";
	if (revenue >= 0.0)
		std::cout << revenue;
	else
		std::cout << "UNDEFINED";
}


//PRIVATE----------------------------------------------------------------------------


// Converts 'T' into minutes.
// Returns -1 if time is invalid.
// 24:00 and 00:00 are both valid time.
int ComputerStore::isTimeValid(const char* T) const {
	if (notDig(T[0]) || notDig(T[1]) || T[2] != ':' || notDig(T[3]) || notDig(T[4])) {
		return -1;
	}

	// Convert to minutes.
	int minutes = (T[0] - 48) * 600 + (T[1] - 48) * 60 + (T[3] - 48) * 10 + T[4] - 48;
	if (1440 < minutes)		// 24:00 == 1440 minutes
		return -1;

	return minutes;
}

bool ComputerStore::notDig(char c) const {
	return c < '0' || '9' < c;
}

void ComputerStore::checkAndChangeIsObjInit() {
	IS_OBJ_INIT = (storeName && *workHours && revenue >= 0.0);
}

void ComputerStore::Null() {
	storeName = nullptr;
	products = nullptr;
	availability = nullptr;
	revenue = -1.0;
	productCount = 0;
	*workHours = 0;
	IS_OBJ_INIT = false;
}

void ComputerStore::deleteProductsAndAvailability() {
	delete[] products;
	delete[] availability;
	products = nullptr;
	availability = nullptr;
}

void ComputerStore::copyProductsAndAvailabitity(const ComputerPart* CPFrom, ComputerPart* CPTo, const size_t* AVFrom, size_t* AVTo, size_t count) {
	for (size_t i = 0; i < count; ++i) {
		CPTo[i].setComputerPartOnce(CPFrom[i]);
		AVTo[i] = AVFrom[i];
	}
}
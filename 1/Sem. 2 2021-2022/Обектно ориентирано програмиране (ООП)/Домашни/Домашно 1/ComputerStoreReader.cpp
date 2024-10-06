
#include "ComputerStoreReader.h"


//PUBLIC-----------------------------------------------------------------------------

ComputerStoreReader::ComputerStoreReader(){}
ComputerStoreReader::ComputerStoreReader(const char* fileName) {
	setFileName(fileName);
}
ComputerStoreReader::ComputerStoreReader(const ComputerStoreReader& other) {
	*this = other;
}
ComputerStoreReader& ComputerStoreReader::operator=(const ComputerStoreReader& other) {
	if (this != &other) {
		delete[] fileName;

		if (other.fileName) {
			fileName = new char[strlen(other.fileName) + 1];
			strcpy(fileName, other.fileName);
		}
		else {
			fileName = nullptr;
		}
	}

	return *this;
}
ComputerStoreReader::~ComputerStoreReader() {
	delete[] fileName;
}

// Returns -1 if can not open file,
//			0 if error during reading from file, or file is incorrectly formated,
//			1 of it was successful.
int ComputerStoreReader::readStoreFromFile(ComputerStore& store) const {
	if (!fileName)
		return -1;
	
	std::ifstream ifile(fileName);
	if (!ifile.is_open())
		return -1;

	char storeName[MAX_SIZE];
	ifile.getline(storeName, MAX_SIZE);

	char workHours[12];
	ifile.get(workHours, 12);
	workHours[11] = '\0';

	size_t productCount = 0;
	ifile >> productCount;

	char c = 0;
	ifile >> c;
	if (c != '[' || !ifile.good())
		return 0;

	ComputerPart* products = new ComputerPart[productCount];
	size_t* availability = new size_t[productCount];
	
	size_t i = 0;
	for (; i < productCount; ++i) {
		if (1 != CPreader.readCPFromFile(ifile, products[i])) {
			break;
		}
		ifile >> availability[i];
	}

	ifile >> c;
	if (c != ']' || i < productCount || !ifile.good()) {
		delete[] products;
		delete[] availability;
		return 0;
	}

	double revenue = -1.0;
	ifile >> revenue;

	store.setStoreName(storeName);
	store.setWorkHours(workHours);
	store.setRevenue(revenue);
	store.replaceProducts(products, availability, productCount);

	delete[] products;
	delete[] availability;
	ifile.close();

	return 1;
}

const char* ComputerStoreReader::getFileName() const { return fileName; }

bool ComputerStoreReader::setFileName(const char* newFileName) {
	if (!newFileName)
		return false;

	size_t len = strlen(newFileName);
	if (len == 0)		// Don't accept empty names.
		return false;

	delete[] fileName;
	fileName = new char[len + 1];
	strcpy(fileName, newFileName);

	return true;
}

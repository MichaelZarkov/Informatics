
#include "ComputerPartReader.h"



//PUBLIC----------------------------------------------------------------------------


ComputerPartReader::ComputerPartReader(){}
ComputerPartReader::ComputerPartReader(const char* newFileName) {
	openFile(newFileName);
}
ComputerPartReader::ComputerPartReader(const ComputerPartReader& other) {
	openFile(other.fileName);
}
ComputerPartReader& ComputerPartReader::operator=(const ComputerPartReader& other) {
	if (this != &other) {
		openFile(other.fileName);
	}

	return *this;
}
ComputerPartReader::~ComputerPartReader() {
	closeFile();
	delete[] fileName;
}


bool ComputerPartReader::openFile(const char* newFileName) {
	if (!copyFileName(newFileName))
		return false;

	closeFile();

	return openFile();
}
bool ComputerPartReader::openFile(){ 
	if (ifile.is_open())
		return true;

	ifile.open(fileName, std::ios::app);
	if (!ifile.is_open()) {
		ifile.clear();
		return false;
	}

	return true;
}
void ComputerPartReader::closeFile() {
	if (ifile.is_open())
		ifile.close();

	ifile.clear();
}


int ComputerPartReader::readCPFromFile(ComputerPart& CP) {
	int returnValue = readCPFromFile(ifile, CP);
	if (!ifile.good())
		ifile.clear();

	return returnValue;
}
// Returns -1 if file is not opened, 'CP' is already initialized,
//			0 if an error occurs during reading, or is incorectly formatted (nothing is written in the object),
//			1 if operation was successful.
int ComputerPartReader::readCPFromFile(std::ifstream& inputFile, ComputerPart& CP) const {
	if (!inputFile.is_open() || CP.isObjInit())
		return -1;

	char c = 0;
	inputFile >> c;
	if (c != '{')
		return 0;


	char type[MAX_SIZE];
	inputFile.getline(type, MAX_SIZE, '|');

	char brand[MAX_SIZE];
	inputFile.getline(brand, MAX_SIZE, '|');

	char model[MAX_SIZE];
	inputFile.getline(model, MAX_SIZE, '|');

	size_t warranty = 0;
	inputFile >> warranty;

	inputFile >> c;
	if (c != '|') 
		return 0;
	
	double price = -1.0;
	inputFile >> price;

	inputFile >> c;
	if (c != '}' || !inputFile.good()) 
		return 0;

	if (1 != CP.setComputerPartOnce(brand, model, price, warranty, type)) {
		return 0;
	}

	return 1;
}

const char* ComputerPartReader::getFileName() const { return fileName; }
bool ComputerPartReader::isOpen() const { return ifile.is_open(); }


//PRIVATE----------------------------------------------------------------------------


bool ComputerPartReader::copyFileName(const char* newFileName) {
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
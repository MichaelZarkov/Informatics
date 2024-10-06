
#include "ComputerPartWriter.h"


//PUBLIC----------------------------------------------------------------------------


ComputerPartWriter::ComputerPartWriter() : fileName(nullptr) {}

ComputerPartWriter::ComputerPartWriter(const char* fileName) {
	openFile(fileName);
}

ComputerPartWriter::ComputerPartWriter(const ComputerPartWriter& other) {
	openFile(other.fileName);
}

ComputerPartWriter& ComputerPartWriter::operator=(const ComputerPartWriter& other) {
	if (this != &other) {
		openFile(other.fileName);
	}

	return *this;
}

ComputerPartWriter::~ComputerPartWriter() {
	closeFile();
	delete[] fileName;
}


bool ComputerPartWriter::openFile(const char* fileName) {
	if (!copyFileName(fileName))
		return false;

	closeFile();

	return openFile();
}

bool ComputerPartWriter::openFile() {
	if (ofile.is_open())
		return true;

	ofile.open(fileName, std::ios::app);
	if (!ofile.is_open()) {
		ofile.clear();
		return false;
	}

	return true;
}
void ComputerPartWriter::closeFile() {
	if (ofile.is_open())
		ofile.close();

	ofile.clear();
}
void ComputerPartWriter::flush() { ofile.flush(); }

int ComputerPartWriter::writeCPInFile(const ComputerPart& CP) {	
	int returnValue = writeCPInFile(ofile, CP);
	if (!ofile.good())
		ofile.clear();
	
	return returnValue;
}
// Returns -1 if file is not opened,
//			0 if there was an error during writing to the file (possible corruption of the file),
//			1 if operation was successful,
//			2 if 'CP' is uninitialized object (does not write it in file).
int ComputerPartWriter::writeCPInFile(std::ofstream& file, const ComputerPart& CP) {
	if (!file.is_open())
		return -1;

	if (CP.isObjInit()) {
		file << '{' << CP.getType() << '|' << CP.getBrand()
			<< '|' << CP.getModel() << '|' << CP.getWarranty()
			<< '|' << CP.getPrice() << "}";
	}
	else {
		return 2;
	}

	if (file.good()) {
		return 1;
	}

	return 0;
}

const char* ComputerPartWriter::getFileName() const { return fileName; }
bool ComputerPartWriter::isOpen() const { return ofile.is_open(); }

//PRIVATE----------------------------------------------------------------------------

bool ComputerPartWriter::copyFileName(const char* newFileName) {
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

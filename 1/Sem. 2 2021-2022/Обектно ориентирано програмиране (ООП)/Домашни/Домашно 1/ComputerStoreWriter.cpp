
#include "ComputerStoreWriter.h"


ComputerStoreWriter::ComputerStoreWriter(){}
ComputerStoreWriter::ComputerStoreWriter(const char* fileName) {
	setFileName(fileName);
}
ComputerStoreWriter::ComputerStoreWriter(const ComputerStoreWriter& other) {
	setFileName(other.fileName);
}
ComputerStoreWriter& ComputerStoreWriter::operator=(const ComputerStoreWriter& other) {
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
ComputerStoreWriter::~ComputerStoreWriter() {
	delete[] fileName;
}

const char* ComputerStoreWriter::getFileName() const { return fileName; }

bool ComputerStoreWriter::setFileName(const char* newFileName) {
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

// Does not write in file if 'CS' is not initialized. 
// Returns -2 if 'CS' is not initialized,
//		   -1 if the file can not be opened,
//			0 if there was an error during writing to the file (possible corruption of the file),
//			1 if operation was successuful.
int ComputerStoreWriter::writeStoreInFile(const ComputerStore& CS) {
	if (!CS.isObjInit())
		return -2;

	if (!fileName)
		return -1;

	std::ofstream ofile(fileName);
	if (!ofile.is_open())
		return -1;

	ofile << CS.getStoreName() << '\n' << CS.getWorkHours() << '\n' << CS.getProductCount() << '\n';
	ofile << "[\n";

	size_t i = 0;
	for (; i < CS.getProductCount() && ofile.good(); ++i) {
		ofile << "    ";
		CPwriter.writeCPInFile(ofile, CS.getProducts()[i]);
		ofile << " " << CS.getAvailability()[i] << '\n';
	}

	ofile << "]\n" << CS.getRevenue();

	if (!ofile.good()) {
		ofile.clear();
		ofile.close();
		return 0;
	}
		
	ofile.flush();
	ofile.close();
	return 1;
}

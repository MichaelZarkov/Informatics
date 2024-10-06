
#pragma once
#include "ComputerStore.h"
#include "ComputerPartReader.h"


class ComputerStoreReader {
private:

	ComputerPartReader CPreader;
	char* fileName{ nullptr };

public:

	ComputerStoreReader();
	ComputerStoreReader(const char* fileName);
	ComputerStoreReader(const ComputerStoreReader&);
	ComputerStoreReader& operator=(const ComputerStoreReader&);
	~ComputerStoreReader();

	int readStoreFromFile(ComputerStore&) const;

	const char* getFileName() const;
	bool setFileName(const char* newFileName);	// Returns false if 'newFileName' is invalid file name.

};
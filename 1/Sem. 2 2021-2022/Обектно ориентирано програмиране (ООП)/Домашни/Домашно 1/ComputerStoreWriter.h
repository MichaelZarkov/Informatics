
#pragma once
#include "ComputerPartWriter.h"
#include "ComputerStore.h"

class ComputerStoreWriter {
private:
	ComputerPartWriter CPwriter;
	char* fileName{ nullptr };

public:

	ComputerStoreWriter();
	ComputerStoreWriter(const char* fileName);
	ComputerStoreWriter(const ComputerStoreWriter&);
	ComputerStoreWriter& operator=(const ComputerStoreWriter&);
	~ComputerStoreWriter();

	int writeStoreInFile(const ComputerStore&);

	const char* getFileName() const;
	bool setFileName(const char* newFileName);	// Returns false if 'newFileName' is invalid file name.
};
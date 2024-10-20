﻿
#pragma once
#include <fstream>
#include "ComputerPart.h"

const size_t MAX_SIZE = 64;

class ComputerPartReader {
private:
	std::ifstream ifile;
	char* fileName{ nullptr };

public:
	
	ComputerPartReader();
	ComputerPartReader(const char* newFileName);
	ComputerPartReader(const ComputerPartReader&);
	ComputerPartReader& operator=(const ComputerPartReader&);
	~ComputerPartReader();

	bool openFile(const char* newFileName);		// Returns true if file was opened successfully. False if file can't be opened.
	bool openFile();							// Open file 'fileName'.
	void closeFile();							// Close file 'fileName'.

	int readCPFromFile(ComputerPart&);	       
	int readCPFromFile(std::ifstream&, ComputerPart&) const;	// Returns 1 if if was successful.

	const char* getFileName() const;
	bool isOpen() const;

private:
	
	bool copyFileName(const char* newFileName);	// Returns false if 'newFileName' is invalid file name.
};
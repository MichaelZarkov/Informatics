
#pragma once
#include "ComputerPart.h"

class ComputerStore {
private:
	char* storeName;
	ComputerPart* products;
	size_t* availability;
	double revenue;
	size_t productCount;
	char workHours[12];		// Format 'HH:MM-HH:MM' (11 simbols + '\0').
	
	bool IS_OBJ_INIT;		// A store is initialized if 'storeName', 'revenue' and 'workHours' have a user defined value
							// A store with 0 products is considered initialized.

public:

	ComputerStore();
	ComputerStore(const char* name, const ComputerPart*, const size_t*, size_t productCount, double, const char* workH);
	ComputerStore(const ComputerStore&);
	ComputerStore& operator=(const ComputerStore&);
	~ComputerStore();

	bool addProduct(const ComputerPart&, size_t av);
	bool removeProduct(const ComputerPart&);								// False if it couldn't find the same product.
	bool findProduct(const char* type, const char* brand) const;			// True if there is a product with the given type and brand.
	void replaceProducts(const ComputerPart*, const size_t*, size_t count); // Deletes the current products in the store and replaces them with the given.

	bool setRevenue(double revenue);
	bool setStoreName(const char* newName);
	bool setWorkHours(const char* workH);
	
	const ComputerPart* getProducts() const;
	const size_t* getAvailability() const;
	const char* getWorkHours() const;
	const char* getStoreName() const;
	double getRevenue() const;
	size_t getProductCount() const;
	bool isObjInit() const;

	void print();

private:

	int isTimeValid(const char* H) const;
	bool notDig(char c) const;				// Returns true if 'c' is NOT a digit.
	void checkAndChangeIsObjInit();
	void Null();
	void deleteProductsAndAvailability();
	void copyProductsAndAvailabitity(const ComputerPart*, ComputerPart*, const size_t*, size_t*, size_t);
};
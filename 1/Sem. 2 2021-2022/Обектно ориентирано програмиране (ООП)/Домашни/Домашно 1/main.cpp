
#include "ComputerPartReader.h"
#include "ComputerStoreWriter.h"
#include "ComputerStoreReader.h"

int main() {
	
	//Computer Part--------------------------------------------------------------------

	ComputerPart CParr1[5];

	CParr1[0].setComputerPartOnce("Sony", "Xperia", 150, 1, "MONITOR");
	CParr1[1].setComputerPartOnce("Samsung", "S21", 250, 2, "CAMERA");
	CParr1[2].setComputerPartOnce("Philips", "One Blade", 350, 3, "COMPUTER");
	CParr1[3].setComputerPartOnce("HP", "Legion", 450, 4, "LAPTOP");
	CParr1[4].setComputerPartOnce("Acer", "Nitro", 550, 5, "MOUSE");

	std::cout << "Array 1:\n";
	for (int i = 0; i < 5; ++i) {
		CParr1[i].print();
		std::cout << std::endl;
	}


	// Write Computer parts in file.
	ComputerPartWriter writer("NotMyFile.txt");
	for (size_t i = 0; i < 5; i++)
	{
		writer.writeCPInFile(CParr1[i]);
	}

	// Read comoputer parts from file.
	ComputerPart CParr2[5];
	ComputerPartReader reader("NotMyFile.txt");
	std::cout << "\n\nArray 2:\n";
	for (size_t i = 0; i < 5; i++)
	{
		reader.readCPFromFile(CParr2[i]);
		CParr2[i].print();
		std::cout << std::endl;
	}


	// Computer store------------------------------------------------------------------

	// Make a store.
	size_t av[5]{ 0, 1, 1, 2, 3 };
	ComputerStore myStore("Amazon", CParr2, av, 5, 1729.0, "07:20-14:40");
	std::cout << "\n\n";
	myStore.removeProduct(*CParr2);			// Remove a product.
	myStore.addProduct(CParr2[4], 20);		// Add a product.
	myStore.print();

	// Write store in file.
	ComputerStoreWriter CSW("computerStore.txt");
	myStore.addProduct(CParr2[4], 25);				// Add a product.
	CSW.writeStoreInFile(myStore);


	// Read store from file.
	ComputerStore mySecondStore;
	ComputerStoreReader CSR("computerStore.txt");
	CSR.readStoreFromFile(mySecondStore);
	std::cout << "\n\n";
	mySecondStore.print();

	std::cout << "\n\n";
}

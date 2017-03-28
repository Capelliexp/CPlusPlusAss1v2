
#include "HousingRegister.h"

void AddHouse(HousingRegister* Register);
void PrintHouses(const HousingRegister* Register);
void PrintHousesUnderValue(const HousingRegister* Register);
void PrintHousesWithCriteria(const HousingRegister* Register);
void RemoveHouse(HousingRegister* Register);
void ChangeHouse(HousingRegister* Register);
void SaveHouses(const HousingRegister* Register);
void ReadHouses(HousingRegister* Register);

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	HousingRegister Register;
	int exit = 0;
	char choice = '0';

	while (exit == 0) {
		std::cout << std::endl << std::endl <<
			"1. Add a house" << std::endl <<
			"2. Show all houses" << std::endl <<
			"3. Show all houses under a certain value" << std::endl <<
			"4. Show all houses with type- and room amount criteria" << std::endl <<
			"5. Remove a house" << std::endl <<
			"6. Change the properties of a house" << std::endl <<
			"7. Save house list to file" << std::endl <<
			"8. Load a house list from file" << std::endl <<
			"9. Exit" <<
			std::endl << std::endl << ">> ";
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice) {
		case '1':
			AddHouse(&Register);
			break;
		case '2':
			PrintHouses(&Register);
			break;
		case '3':
			PrintHousesUnderValue(&Register);
			break;
		case '4':
			PrintHousesWithCriteria(&Register);
			break;
		case '5':
			RemoveHouse(&Register);
			break;
		case '6':
			ChangeHouse(&Register);
			break;
		case '7':
			SaveHouses(&Register);
			break;
		case '8':
			ReadHouses(&Register);
			break;
		case '9':
			exit = 1;
			break;
		default:
			std::cout << "Unhandled command" << std::endl;
			fflush(stdout);
			break;
		}
	}
	std::cout << "Goodbye";
	return 0;
}

void AddHouse(HousingRegister* Register) {
	int id, rent, area, rooms;
	std::string address, propertyType;

	std::cout << "House ID: ";
	std::cin >> id;

	std::cout << "House rent: ";
	std::cin >> rent;

	std::cout << "Property area: ";
	std::cin >> area;

	std::cout << "House rooms: ";
	std::cin >> rooms;

	std::cout << "House address: ";
	std::cin >> address;

	std::cout << "Property Type: ";
	std::cin >> propertyType;

	bool result = Register->AddHousing(id, address, rent, propertyType, area, rooms);

	if (result == false) {
		std::cout << "Failed to create house listing" << std::endl;
	}
}

void PrintHouses(const HousingRegister* Register) {
	unsigned int size = Register->GetSize();

	std::string* daString = new std::string[size + 1];
	Register->PresentAllHousing(daString);

	for (int i = 0; i < size; i++) {
		std::cout << "   " << daString[i] << std::endl;
	}

	delete[] daString;
}
 
void PrintHousesUnderValue(const HousingRegister* Register) {
	int upperValue;

	std::cout << "House maximum value: ";
	std::cin >> upperValue;

	unsigned int size = Register->GetSize();

	std::string* daString = new std::string[size + 1];
	int unused = Register->PresentHousingUnderValue(daString, upperValue);

	if ((size - unused) > 0) {
		for (int i = 0; i < size - unused; i++) {
			std::cout << "   " << daString[i] << std::endl;
		}
	}
	else {
		std::cout << "No houses matching that criteria" << std::endl;
	}

	delete[] daString;
}

void PrintHousesWithCriteria(const HousingRegister* Register) {
	std::string propertyType;
	int roomsAmount;

	std::cout << "House room amount: ";
	std::cin >> roomsAmount;

	std::cout << "House property type: ";
	std::cin >> propertyType;

	unsigned int size = Register->GetSize();

	std::string* daString = new std::string[size + 1];
	int unused = Register->PresentHousingWithCriteria(daString, propertyType, roomsAmount);

	if ((size - unused) > 0) {
		for (int i = 0; i < size - unused; i++) {
			std::cout << "   " << daString[i] << std::endl;
		}
	}
	else {
		std::cout << "No houses matching that criteria" << std::endl;
	}
	
	delete[] daString;
}

void RemoveHouse(HousingRegister* Register) {
	int id;

	std::cout << "ID of house to remove: ";
	std::cin >> id;

	Register->RemoveHousing(id);
}

void ChangeHouse(HousingRegister* Register) {
	int id, rent, area, rooms;
	std::string address, propertyType;

	std::cout << "ID of house to change: ";
	std::cin >> id;

	std::cout << "New house rent: ";
	std::cin >> rent;

	std::cout << "New property area: ";
	std::cin >> area;

	std::cout << "New house rooms: ";
	std::cin >> rooms;

	std::cout << "New house address: ";
	std::cin >> address;

	std::cout << "New property Type: ";
	std::cin >> propertyType;

	Register->ChangeHousingProperties(id, address, rent, propertyType, area, rooms);
}

void SaveHouses(const HousingRegister* Register) {
	std::string fileName;
	std::cout << "Name of save file: ";
	std::cin >> fileName;

	Register->SaveAllHousing(fileName);
}

void ReadHouses(HousingRegister* Register){
	std::string fileName;
	std::cout << "Name of file to load housing data from: ";
	std::cin >> fileName;

	bool result = Register->ReadAllHousing(fileName);

	if (result == true) {
		std::cout << "file loaded successfully" << std::endl;
	}
	else {
		std::cout << "load operation failed" << std::endl;
	}
}
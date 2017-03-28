#include "HousingRegister.h"

void ReadFromStringArray(const HousingRegister* Register);

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::cout << "Tryck för att starta testet" << std::endl;
	getchar();

	std::cout << "<skapa HousingRegister-objektet (start kap 2)>" << std::endl;
	HousingRegister Register(2);

	std::cout << "<skapa 2 hus>" << std::endl;
	/*>>>*/Register.AddHousing(1, "Gata 1", 2, "HusTyp1", 3, 4);
	/*>>>*/Register.AddHousing(2, "Gata 2", 3, "HusTyp2", 4, 5);

	std::cout << "<Läs hela listan>" << std::endl << std::endl;
	/*>>>*/ReadFromStringArray(&Register);

	std::cout << std::endl << "<skapa ytterligare 1 hus>" << std::endl;
	/*>>>*/Register.AddHousing(3, "Gata 3", 4, "HusTyp3", 5, 6);

	std::cout << "<Läs hela listan>" << std::endl << std::endl;
	/*>>>*/ReadFromStringArray(&Register);

	std::cout << std::endl << "<ta bort bostaden med ID 4 (existerar ej)>" << std::endl;
	/*>>>*/Register.RemoveHousing(4);

	std::cout << "<Läs hela listan>" << std::endl << std::endl;
	/*>>>*/ReadFromStringArray(&Register);
	std::cout << std::endl << "           ^^ som vi ser har inte något element tagits bort ^^" << std::endl;

	std::cout << std::endl << "<ta bort bostaden med ID 2 (existerar)>" << std::endl;
	/*>>>*/Register.RemoveHousing(2);

	std::cout << "<Läs hela listan>" << std::endl << std::endl;
	/*>>>*/ReadFromStringArray(&Register);
	std::cout << std::endl << " ^^ som vi ser har det andra elementet tagits bort (för att det hade ID: 2) ^^" << std::endl;

	std::cout << std::endl << "<ta bort de resterande bostäderna (ID 1 & 3)>" << std::endl;
	/*>>>*/Register.RemoveHousing(1);
	/*>>>*/Register.RemoveHousing(3);

	std::cout << "<Läs hela listan>" << std::endl << std::endl;
	/*>>>*/ReadFromStringArray(&Register);

	std::cout << "^^ Som vi ser är listan tom ^^" << std::endl << std::endl;

	std::cout << "<skapa 2 hus>" << std::endl;
	/*>>>*/Register.AddHousing(4, "Gata 4", 5, "HusTyp4", 6, 7);
	/*>>>*/Register.AddHousing(5, "Gata 5", 6, "HusTyp5", 7, 8);

	std::cout << "<Läs hela listan>" << std::endl << std::endl;
	/*>>>*/ReadFromStringArray(&Register);
	std::cout << std::endl << "               ^^ Som vi ser har listan de 2 nya objekten ^^" << std::endl << std::endl;

	std::cout << "Tryck för att starta test för copykonstruktor och tilldelningsoperator" << std::endl;
	getchar();

	std::cout << "-------------------------------------------------------------------------------------" << std::endl << std::endl;

	std::cout << "<skapa en ny HousingRegister genom: FakeRegister(Register)>" << std::endl;
	HousingRegister FakeRegister(Register);

	std::cout << "skriv allt innehåll från båda registren till var sin string array och jämför dessa" << std::endl << std::endl;
	std::string string1[10], string2[10];
	Register.PresentAllHousing(string1);
	FakeRegister.PresentAllHousing(string2);

	bool testFailStateCopy = false;
	for (int i = 0; i < 10; i++) {
		if (string1[i] != string2[i]) {
			testFailStateCopy = true;
		}
	}

	if (testFailStateCopy == false && (Register.GetSize() == FakeRegister.GetSize()) && (Register.GetFreeSpace() == FakeRegister.GetFreeSpace())) {
		std::cout << "     copykonstruktor fungerar fint" << std::endl;
	}
	else {
		std::cout << "     copykonstruktor fungerar EJ" << std::endl;
	}

	std::cout << std::endl << "<Ändra både Register & FakeRegister, så de blir olika>" << std::endl;
	Register.AddHousing(1, "Gata 1", 2, "HusTyp1", 3, 4);
	FakeRegister.RemoveHousing(5);

	std::cout << "<sätt FakeRegister = Register>" << std::endl;
	FakeRegister = Register;

	std::cout << std::endl << "skriv allt innehåll från båda registren till var sin string array och jämför dessa" << std::endl << std::endl;
	std::string string3[10], string4[10];
	Register.PresentAllHousing(string3);
	FakeRegister.PresentAllHousing(string4);

	bool testFailStateAssignment = false;
	for (int i = 0; i < 10; i++) {
		if (string3[i] != string4[i]) {
			testFailStateAssignment = true;
		}
	}

	if (testFailStateAssignment == false && (Register.GetSize() == FakeRegister.GetSize()) && (Register.GetFreeSpace() == FakeRegister.GetFreeSpace())) {
		std::cout << "     assignment operator fungerar fint" << std::endl;
	}
	else {
		std::cout << "     assignment operator fungerar EJ" << std::endl;
	}

	getchar();
	return 0;
}

void ReadFromStringArray(const HousingRegister* Register) {
	std::string daString[9];
	Register->PresentAllHousing(daString);

	for (int i = 0; i < Register->GetSize(); i++) {
		std::cout << "   " << daString[i] << std::endl;
	}
}
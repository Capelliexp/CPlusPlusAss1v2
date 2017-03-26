#include <string>
#include <iostream>
#include <crtdbg.h>
#include "HousingRegister.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::cout << "Press any key to start test" << std::endl;
	getchar();

	//HousingRegister Register(2);

	//Register.AddHousing(1, "Gata 1", 2, "Villa", 3, 4);
	//Register.AddHousing(2, "Gata 2", 3, "Villa", 4, 5);

	//std::string A[2];
	//Register.PresentAllHousing(A);
	//std::cout << A << std::endl;

	getchar();
	return 0;
}
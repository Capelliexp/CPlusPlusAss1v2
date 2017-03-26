#ifndef HOUSINGREGISTER_H
#define HOUSINGREGISTER_H

#include "Housing.h"
#include <string>

class HousingRegister {
private:
	Housing** HousingList;
	int size;
	int freeSpace;
public:
	void AddHousing();
	std::string* PresentAllHousing(std::string stringList) const;
	void PresentHousingUnderValue() const;
	void PresentHousingWithCriteria() const;
	void RemoveHousing();
	void ChangeHousingProperties();
	void SaveAllHousing() const;
	void ReadAllHousing();

	HousingRegister(HousingRegister &other);	//copy construct
	HousingRegister& operator=(HousingRegister &other);	//assignment operator

	HousingRegister(const int startValue);
	~HousingRegister();
};
#endif
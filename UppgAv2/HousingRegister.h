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
	int GetSize() const;
	int GetFreeSpace() const;
	Housing* GetHousingItem(const int itemPosition) const;

	void AddHousing(const int id, const std::string adress, const int rent, const std::string propertyType, const int area, const int rooms);
	void PresentAllHousing(std::string stringList[]) const;
	void PresentHousingUnderValue(std::string stringList[], const int valueParam) const;
	void PresentHousingWithCriteria(std::string stringList[], const std::string propertyTypeParam, const int roomsParam) const;
	void RemoveHousing(const int idParam);
	void ChangeHousingProperties(const int idParam, const std::string newAddress, const int newRent, const std::string newPropertyType, const int newArea, const int newRooms);
	void SaveAllHousing() const;
	void ReadAllHousing();

	HousingRegister(const HousingRegister &other);	//copy construct
	HousingRegister& operator=(const HousingRegister &other);	//assignment operator

	HousingRegister(const int startValue = 1);
	~HousingRegister();
};
#endif
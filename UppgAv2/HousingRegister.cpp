#include "HousingRegister.h"

int HousingRegister::GetSize() const {
	return this->size;
}
int HousingRegister::GetFreeSpace() const {
	return this->freeSpace;
}
Housing* HousingRegister::GetHousingItem(const int itemPosition) const {
	return this->HousingList[itemPosition];
}

void HousingRegister::AddHousing(const int id, const std::string adress, const int rent, const std::string propertyType,
	const int area, const int rooms) {
	if (freeSpace > 0) {
		HousingList[size] = new Housing(id, adress, rent, propertyType, area, rooms);
		this->size++;
		this->freeSpace--;
	}
	else {
		Housing** temp = new Housing*[size + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = HousingList[i];
		}
		temp[size] = new Housing(id, adress, rent, propertyType, area, rooms);

		delete[] this->HousingList;
		this->HousingList = temp;

		this->size++;
	}
}

void HousingRegister::PresentAllHousing(std::string stringList[]) const {
	for (int i = 0; i < size; i++) {
		stringList[i] = HousingList[i]->toString();
	}
}

void HousingRegister::PresentHousingUnderValue(std::string stringList[], const int valueParam) const {
	int listSpaceUsed = 0;
	for (int i = 0; i < size; i++) {
		if (HousingList[i]->GetRent() < valueParam) {
			stringList[listSpaceUsed] = HousingList[i]->toString();
			listSpaceUsed++;
		}
		
	}
}

void HousingRegister::PresentHousingWithCriteria(std::string stringList[], const std::string propertyTypeParam,
	const int roomsParam) const {
	int listSpaceUsed = 0;
	for (int i = 0; i < size; i++) {
		if ((HousingList[i]->GetRooms() == roomsParam) && (HousingList[i]->GetPropertyType() == propertyTypeParam)) {
			stringList[listSpaceUsed] = HousingList[i]->toString();
			listSpaceUsed++;
		}
		
	}
}

void HousingRegister::RemoveHousing(const int idParam) {
	for (int i = 0; i < size; i++) {
		if (HousingList[i]->GetID() == idParam) {
			delete[] this->HousingList[i];

			for (int j = i + 1; j < size - 1; j++) {
				HousingList[j - 1] = HousingList[j];
			}
			HousingList[size] = nullptr;
			this->size--;
			this->freeSpace++;
			i--;
		}
	}	//da "early returns ar inte tillatna, break endast i samband med ev switch/case" maste for-satsen fortsatta
}		//trotts att vi vet att ID:t ar unikt. (Man skulle kunna satta i = size, men det blir ju inte alls snyggt...)

void HousingRegister::ChangeHousingProperties(const int idParam, const std::string newAddress, const int newRent,
	const std::string newPropertyType, const int newArea, const int newRooms) {
	for (int i = 0; i < size; i++) {
		if (HousingList[i]->GetID() == idParam) {
			HousingList[i]->SetAddress(newAddress);
			HousingList[i]->SetRent(newRent);
			HousingList[i]->SetPropertyType(newPropertyType);
			HousingList[i]->SetArea(newArea);
			HousingList[i]->SetRooms(newRooms);
		}
	}
}

void HousingRegister::SaveAllHousing() const {}

void HousingRegister::ReadAllHousing() {}

HousingRegister::HousingRegister(const HousingRegister &other) {
	this->size = other.GetSize();
	this->freeSpace = other.GetFreeSpace();

	this->HousingList = new Housing*[size + freeSpace];

	for (int i = 0; i < size; ) {
		this->HousingList[i] = new Housing(
			other.GetHousingItem(i)->GetID(), other.GetHousingItem(i)->GetAddress(),
			other.GetHousingItem(i)->GetRent(), other.GetHousingItem(i)->GetPropertyType(),
			other.GetHousingItem(i)->GetArea(), other.GetHousingItem(i)->GetRooms()
		);
	}
}
HousingRegister& HousingRegister::operator=(const HousingRegister &other) {
	if (&other != this) {
		delete[] this->HousingList;

		this->size = other.GetSize();
		this->freeSpace = other.GetFreeSpace();

		this->HousingList = new Housing*[size + freeSpace];

		for (int i = 0; i < size; ) {
			this->HousingList[i] = new Housing(
				other.GetHousingItem(i)->GetID(), other.GetHousingItem(i)->GetAddress(),
				other.GetHousingItem(i)->GetRent(), other.GetHousingItem(i)->GetPropertyType(),
				other.GetHousingItem(i)->GetArea(), other.GetHousingItem(i)->GetRooms()
			);
		}
	}
	return *this;
}

HousingRegister::HousingRegister(const int startValue) {
	this->HousingList = new Housing*[startValue];
	this->size = 0;
	this->freeSpace = startValue;
}
HousingRegister::~HousingRegister() {
	for (int i = 0; i < size; i++) {	//for kanske inte behovs...
		delete HousingList[i];
	}
	delete[] this->HousingList;
}
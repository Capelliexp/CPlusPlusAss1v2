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

bool HousingRegister::AddHousing(const int id, const std::string address, const int rent, const std::string propertyType,
	const int area, const int rooms) {
	bool endValue = true;

	for (int i = 0; i < size; i++) {
		if (HousingList[i]->GetID() == id) {
			endValue = false;
		}
	}

	if (endValue == true) {
		if (freeSpace > 0) {
			HousingList[size] = new Housing(id, address, rent, propertyType, area, rooms);
			this->size++;
			this->freeSpace--;
		}
		else {
			Housing** temp = new Housing*[size + 1];
			for (int i = 0; i < size; i++) {
				temp[i] = HousingList[i];
			}
			temp[size] = new Housing(id, address, rent, propertyType, area, rooms);

			delete[] this->HousingList;
			this->HousingList = temp;

			this->size++;
		}
	}	
	return endValue;
}

void HousingRegister::PresentAllHousing(std::string stringList[]) const {
	for (int i = 0; i < size; i++) {
		stringList[i] = HousingList[i]->toString();
	}
}

int HousingRegister::PresentHousingUnderValue(std::string stringList[], const int valueParam) const {
	int listSpaceUsed = 0;
	int unusedAmount = 0;
	for (int i = 0; i < size; i++) {
		if (HousingList[i]->GetRent() < valueParam) {
			stringList[listSpaceUsed] = HousingList[i]->toString();
			listSpaceUsed++;
		}
		else {
			unusedAmount++;
		}
	}
	return unusedAmount;
}

int HousingRegister::PresentHousingWithCriteria(std::string stringList[], const std::string propertyTypeParam,
	const int roomsParam) const {
	int listSpaceUsed = 0;
	int unusedAmount = 0;
	for (int i = 0; i < size; i++) {
		if ((HousingList[i]->GetRooms() == roomsParam) && (HousingList[i]->GetPropertyType() == propertyTypeParam)) {
			stringList[listSpaceUsed] = HousingList[i]->toString();
			listSpaceUsed++;
		}
		else {
			unusedAmount++;
		}
	}
	return unusedAmount;
}

void HousingRegister::RemoveHousing(const int idParam) {
	for (int i = 0; i < size; i++) {
		if (HousingList[i]->GetID() == idParam) {
			delete this->HousingList[i];

			for (int j = i; j < size - 1; j++) {
				HousingList[j] = HousingList[j + 1];
			}
			HousingList[size - 1] = nullptr;
			this->size--;
			this->freeSpace++;
			//i--;
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

void HousingRegister::SaveAllHousing(const std::string fileName) const {
	std::ofstream SaveStream;
	SaveStream.open(fileName);

	SaveStream << std::to_string(this->size) << "\n"
		<< std::to_string(this->freeSpace) << "\n";

	for (int i = 0; i < size; i++) {
		SaveStream << std::to_string(HousingList[i]->GetID()) << "%";
		SaveStream << HousingList[i]->GetAddress() << "%";
		SaveStream << std::to_string(HousingList[i]->GetRent()) << "%";
		SaveStream << HousingList[i]->GetPropertyType() << "%";
		SaveStream << std::to_string(HousingList[i]->GetArea()) << "%";
		SaveStream << std::to_string(HousingList[i]->GetRooms()) << "\n";
	}
	SaveStream.close();
}

bool HousingRegister::ReadAllHousing(const std::string fileName) {
	bool goodCall = true;
	std::ifstream LoadStream;
	LoadStream.open(fileName);

	if (LoadStream.is_open()) {
		for (int i = 0; i < size; i++) {
			delete HousingList[i];
		}
		delete[] this->HousingList;

		std::string sizeNew, freeSpaceNew, id, address, rent, propertyType, area, rooms, row;
		size_t divider;

		std::getline(LoadStream, sizeNew);
		std::getline(LoadStream, freeSpaceNew);
		int totalSize = std::stoi(sizeNew) + std::stoi(freeSpaceNew);

		this->HousingList = new Housing*[totalSize];
		this->size = 0;
		this->freeSpace = totalSize;

		for (int i = 0; i < std::stoi(sizeNew); i++) {
			std::getline(LoadStream, row);

			divider = row.find("%");
			id = row.substr(0, divider);
			row = row.substr(divider + 1);

			divider = row.find("%");
			address = row.substr(0, divider);
			row = row.substr(divider + 1);

			divider = row.find("%");
			rent = row.substr(0, divider);
			row = row.substr(divider + 1);

			divider = row.find("%");
			propertyType = row.substr(0, divider);
			row = row.substr(divider + 1);

			divider = row.find("%");
			area = row.substr(0, divider);
			row = row.substr(divider + 1);

			divider = row.find("%");
			rooms = row.substr(0, divider);

			AddHousing(stoi(id), address, stoi(rent), propertyType, stoi(area), stoi(rooms));
		}
	}
	else {
		goodCall = false;
	}
	return goodCall;
}

HousingRegister::HousingRegister(const HousingRegister &other) {
	this->size = other.GetSize();
	this->freeSpace = other.GetFreeSpace();

	this->HousingList = new Housing*[size + freeSpace];

	for (int i = 0; i < size; i++) {
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

		for (int i = 0; i < size; i++) {
			this->HousingList[i] = new Housing(
				other.GetHousingItem(i)->GetID(), other.GetHousingItem(i)->GetAddress(),
				other.GetHousingItem(i)->GetRent(), other.GetHousingItem(i)->GetPropertyType(),
				other.GetHousingItem(i)->GetArea(), other.GetHousingItem(i)->GetRooms()
			);
		}
	}
	return *this;
}

HousingRegister::HousingRegister(int startValue) {
	if (startValue < 1) {
		startValue = 1;
	}

	this->HousingList = new Housing*[startValue];
	this->size = 0;
	this->freeSpace = startValue;
}
HousingRegister::~HousingRegister() {
	for (int i = 0; i < size; i++) {
		delete HousingList[i];
	}
	delete[] this->HousingList;
}
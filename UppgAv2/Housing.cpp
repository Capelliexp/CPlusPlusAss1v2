#include "Housing.h"

int Housing::GetID() const {
	return this->id;
}
std::string Housing::GetAddress() const {
	return this->address;
}
int Housing::GetRent() const {
	return this->rent;
}
std::string Housing::GetPropertyType() const {
	return this->propertyType;
}
int Housing::GetArea() const {
	return this->area;
}
int Housing::GetRooms() const {
	return this->rooms;
}

void Housing::SetID(const int newID) {
	this->id = newID;
}
void Housing::SetAddress(const std::string newAddress) {
	this->address = newAddress;
}
void Housing::SetRent(const int newRent) {
	this->rent = newRent;
}
void Housing::SetPropertyType(const std::string newPropertyType) {
	this->propertyType = newPropertyType;
}
void Housing::SetArea(const int newArea) {
	this->area = newArea;
}
void Housing::SetRooms(const int newRooms) {
	this->rooms = newRooms;
}

std::string Housing::toString() const {
	std::string idString = std::to_string(GetID());
	std::string rentString = std::to_string(rent);
	std::string areaString = std::to_string(area);
	std::string roomsString = std::to_string(rooms);

	return("ID: " + idString + " | Address: " + address + " | Rent: " + rentString +
		" | Type: " + propertyType + " | Area: " + areaString + " | Rooms: " + roomsString);
}

Housing::Housing(const int startID, const std::string startAddress, const int startRent, const std::string startPropertyType, const int startArea, const int startRooms){
	this->id = startID;
	this->address = startAddress;
	this->rent = startRent;
	this->propertyType = startPropertyType;
	this->area = startArea;
	this->rooms = startRooms;
}

Housing::~Housing() {
	//empty
}
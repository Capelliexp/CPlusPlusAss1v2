#ifndef HOUSING_H
#define HOUSING_H

#include <iostream>
#include <string>

class Housing {
private:
	int id;
	std::string address;
	int rent;
	std::string propertyType;
	int area;
	int rooms;
public:
	int GetID() const;
	std::string GetAddress() const;
	int GetRent() const;
	std::string GetPropertyType() const;
	int GetArea() const;
	int GetRooms() const;

	void SetID(const int newID);
	void SetAddress(const std::string newAddress);
	void SetRent(const int newRent);
	void SetPropertyType(const std::string newPropertyType);
	void SetArea(const int newArea);
	void SetRooms(const int newRooms);

	std::string toString() const;

	Housing(const int startID = -1, const std::string startAddress = "NULL", const int startRent = -1, const std::string startPropertyType = "NULL", const int startArea = -1, const int startRooms = -1);
	~Housing();
};
#endif
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

	void SetID(int newID);
	void SetAddress(std::string newAddress);
	void SetRent(int newRent);
	void SetPropertyType(std::string newPropertyType);
	void SetArea(int newArea);
	void SetRooms(int newRooms);

	std::string toString() const;

	Housing(int startID = -1, std::string startAddress = "NULL", int startRent = -1, std::string startPropertyType = "NULL", int startArea = -1, int startRooms = -1);
	~Housing();
};
#endif
#ifndef HOUSING_H
#define HOUSING_H

#include <string>

class Housing {
private:
	int id;
	std::string adress;
	int rent;
	std::string propertyType;
	int area;
	int rooms;
public:
	std::string toString();

	Housing();
	~Housing();
};
#endif
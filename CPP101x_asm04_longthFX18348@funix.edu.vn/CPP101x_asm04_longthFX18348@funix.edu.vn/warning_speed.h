#pragma once
#ifndef WARNING_SPEED_H_
#define WARNING_SPEED_H_
#include <iostream>
#include <fstream>
#include "algorithm.h"
#include "array.h"
using namespace std;
class WarningSpeed : public Algorithm, public Array {
private:
	int speed_range[3];
public:
	WarningSpeed();
	void SetWarningSpeed();	//User set speeds for safe distance warning function
	void PrintWarningSpeed();	//Print speeds to the console
	int* GetSpeed() {
		return speed_range;	//Get speed array from private variable
	}
	int& GetElement(size_t ele) {	//Get each element in the warning speed array 
		return speed_range[ele];
	}
};

#endif //WARNING_SPEED_H_
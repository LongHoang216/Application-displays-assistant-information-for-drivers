#pragma once
#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <iostream>
#include <fstream>
#include <string>
#include "file.h"
#include "warning_speed.h"
using namespace std;

class Vehicle : public WarningSpeed, public File {	//Multi-inheritance
private:
	const string kuser_name = "Long Hoang";  //Default username
	typedef enum {
		R, D
	}CheckGear;
	CheckGear gear;
	int speed = 0;    //Vehicle speed
public:
	void Login(); //Description: Unlock vehicle by typing correct password
	void ChangeGear(); //Description: Changing between gears according to driver's expectation
	void Parking(); //Description: Display P gear on screen
	void Neutral(); //Description: Display N gear on screen
	void Reverse(); //Description: Display R gear on screen
	void Drive(); //Description: Display D gear on screen
	void SafeDistanceWarning();	//Description: Set warning speeds for vehicle
	void ChangeWarningSpeed();	//Description: Option for those who want to change another warning speed
	void CheckSpeed();	//Description: Announce driver whenever vehicle is higher than warning speeds
};

#endif //VEHICLE_H_
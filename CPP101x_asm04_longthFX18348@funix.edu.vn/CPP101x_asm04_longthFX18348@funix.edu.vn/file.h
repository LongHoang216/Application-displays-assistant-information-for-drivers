#pragma once
#ifndef FILE_H_
#define FILE_H_
#include <iostream>
#include <fstream>
#include "default_pass.h"
#include "warning_speed.h"
using namespace std;

class File:public Password {
public:
	bool FileContainPass();	//Check whether file contains default password or not 
	bool FileContainSpeed(); //Check whether file contains warning speeds or not
	void WritePassToFile(Password p);	//Description: Write default password to binary file ASM03.dat
	void ReadPassFromFile(Password &p);	//Description: Read default password from binary file ASM03.dat
	void WriteSpeedToFile(WarningSpeed sp);	//Description: Write password to binary file safe_distance_speed.dat
	void ReadSpeedFromFile(WarningSpeed &sp);	//Description: Read password from binary file safe_distance_speed.dat 
};

#endif //FILE_H_
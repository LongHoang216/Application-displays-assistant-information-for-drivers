#pragma once
#ifndef DEFAULT_PASS_H_
#define DEFAULT_PASS_H_
#include <iostream>	
#include <fstream>
#include "array.h"
#include "algorithm.h"
using namespace std;
class Password : public Array, public Algorithm {
private:
		int default_password[8];
		int user_password[8];
public:
		Password();
		void SetUserPass();		//User enter password to unlock vehicle
		void PrintUserPass();	//Print user password to console
		void SetDefaultPass();	//User enter default password which is used to compare with user password
		void PrintDefaultPass();	//Print default password to the console
		int* GetUserPass() {	//mutator
			return user_password;
		}
		int* GetDefaultPass() {	//mutator
			return default_password;
		}
		void ChangeDefaultPass(); //Description: Option for those who want to change another default password
};
#endif //DEFAULT_PASS_H_
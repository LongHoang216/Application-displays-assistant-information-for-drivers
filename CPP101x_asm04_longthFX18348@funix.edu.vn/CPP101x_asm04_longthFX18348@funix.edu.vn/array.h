#pragma once
#ifndef ARRAY_H_
#define ARRAY_H_
#include <iostream>
#include <string>
using namespace std;

class Array {
public:
	bool IsNumber(string a); //Description: Check whether input is letter or number
	void ArrayIn(int* arr, int size);	//Description: Enter array from keyboard
	void ArrayOut(int* arr, int size);	//Description: Print array
	bool IsEqual(int* arr1, int size1, int* arr2, int size2);	//Description: Compare 2 array's members
};
#endif //ARRAY_H_
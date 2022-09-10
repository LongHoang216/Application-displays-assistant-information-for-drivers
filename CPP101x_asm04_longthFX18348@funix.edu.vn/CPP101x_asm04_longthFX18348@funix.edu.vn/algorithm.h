#pragma once
#include <iostream>
using namespace std;
#ifndef ALGORITHM_H_
#define ALGORITHM_H_

class Algorithm {
public:
	int BubbleSort_step = 0, SelectionSort_step = 0;
	void swap(int* a, int* b);	//Description: Swap position of 2 number
	void BubbleSort(int* arr, int size);
	void SelectionSort(int* arr, int size);
};


#endif //ALGORITHM_H_
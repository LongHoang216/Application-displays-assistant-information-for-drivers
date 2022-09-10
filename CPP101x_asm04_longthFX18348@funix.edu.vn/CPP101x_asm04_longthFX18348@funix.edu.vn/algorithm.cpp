#include "algorithm.h"

void Algorithm::swap(int* a, int* b) {  //Change position of 2 number
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Function declaration
void Algorithm::BubbleSort(int* arr, int size) {
    int* ptr = arr;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            BubbleSort_step++;    //the algorithm consume 1 step to make comparison
            if (*(ptr + j + 1) < *(ptr + j)) {
                swap((ptr + j + 1), (ptr + j));
                BubbleSort_step++; //the algorithm consume 1 step to swap
            }
        }
    }
}
void Algorithm::SelectionSort(int* arr, int size) {
    int* ptr = arr;
    for (int i = 0; i < size - 1; i++) {
        int min_position = i;
        for (int j = i + 1; j < size; j++)
        {
            SelectionSort_step++; //the algorithm consume 1 step to make comparison
            if (*(ptr + j) < *(ptr + min_position)) {
                min_position = j;
            }
        }
        swap((ptr + i), (ptr + min_position));
        SelectionSort_step++;//the algorithm consume 1 step to swap
    }
}
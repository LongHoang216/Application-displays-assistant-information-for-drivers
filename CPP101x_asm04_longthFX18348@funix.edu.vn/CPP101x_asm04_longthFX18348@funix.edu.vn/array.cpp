#include "array.h"
bool Array::IsNumber(string a) {
    int check = 0;  //This variable is to check the input is numberic or not
    for (int i = 0; i < a.length(); i++) {
        //If one of member in string contains letters, return false
        if (a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z') {
            check += 1;
        }
    }
    //Check = 0 means that the input string only contain number
    if (check == 0)
        return true;
    else
        return false;
}
void Array::ArrayIn(int* arr, int size) {
    string a[8];
    do {
        system("cls");
        cout << "ENTER PASSWORD" << endl;
        int check = 0;  //This variable is to check whether 8 characters entered from user are number or not 
        for (int i = 0; i < size; i++) {
            cout << "NUMBER " << i + 1 << ": ";
            cin >> a[i];
            if (IsNumber(a[i]) == true) { //If the input contains only number 
                arr[i] = stoi(a[i]);       //Convert from string to int
                check += 1;
            }
        }
        //Check = 8 means that 8 members in the array are acceptable
        if (check == 8)
            break;
        else
            cout << "Errors !!!Please enter again" << endl;
        system("pause");
        cin.ignore(32767, '\n');    //Erase the buffer memory for the next input
    } while (true);
    cout << endl;
}

void Array::ArrayOut(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
bool Array::IsEqual(int* arr1, int size1, int* arr2, int size2) {
    if (size1 != size2)
        return false;
    else {
        for (int i = 0; i < size1; i++) {
            if (arr1[i] != arr2[i]) 
                return false;
        }
        return true;
    }
}
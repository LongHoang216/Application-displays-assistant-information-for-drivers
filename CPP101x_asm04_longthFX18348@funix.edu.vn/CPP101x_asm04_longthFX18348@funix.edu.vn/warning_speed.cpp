#include "warning_speed.h"
WarningSpeed::WarningSpeed() {

}
void WarningSpeed::SetWarningSpeed() {
    string speed1, speed2, speed3;
    do {
        system("cls");
        cout << "SET 3 DIFFERENT SPEED LEVELS FOR SAFE DISTANCE WARNING FUNCTION" << endl;
        cout << "LEVEL 1 SPEED: ";
        cin >> speed1;
        cout << "LEVEL 2 SPEED: ";
        cin >> speed2;
        cout << "LEVEL 3 SPEED: ";
        cin >> speed3;
        //If input contain only number, then assign it for speed ranges
        if (Array::IsNumber(speed1) == true && Array::IsNumber(speed2) == true && Array::IsNumber(speed3) == true) {
            speed_range[0] = stoi(speed1);
            speed_range[1] = stoi(speed2);
            speed_range[2] = stoi(speed3);
            SelectionSort(speed_range, 3);  //Arrange the speed_range array before writing to binary file
            //3 level of speed MUST BE DIFFERENT and different from 0
            if (speed_range[0] != 0 && speed_range[1] != 0 && speed_range[2] != 0 && speed_range[0] != speed_range[1] && speed_range[1] != speed_range[2] && speed_range[0] != speed_range[2]) {
                break;
            }
        }
    } while (true);
}
void WarningSpeed::PrintWarningSpeed() {
    cout << "THREE SPEED LEVELS FOR SAFE DISTANCE WARNING: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << "LEVEL " << i + 1 << " SPEED: " << speed_range[i] << endl;
    }
}

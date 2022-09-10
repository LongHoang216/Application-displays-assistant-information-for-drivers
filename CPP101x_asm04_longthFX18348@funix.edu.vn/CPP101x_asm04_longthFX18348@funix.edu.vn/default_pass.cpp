#include "default_pass.h"
Password::Password() {

}
void Password::SetUserPass() {
	ArrayIn(user_password, 8);  
}
void Password::PrintUserPass() {
	ArrayOut(user_password, 8);
}
void Password::SetDefaultPass() {
	ArrayIn(default_password, 8);
}
void Password::PrintDefaultPass() {
	ArrayOut(default_password, 8);
}
void Password::ChangeDefaultPass() {
    do {
        system("cls");
        cout << "DO YOU WANT TO CHANGE YOUR DEFAULT PASSWORD? (y/n)" << endl;
        string choice;
        cout << "Your choice: ";
        cin >> choice;
        if (choice == "y" || choice == "Y" || choice == "yes" || choice == "YES") {
            Password p;
            p.SetDefaultPass(); //Set default password again when user want to change 
            //Arrange the new array before comparing with the existing one in the binary for accuracy
            //This is because the array saved in the binary file is arranged
            SelectionSort(p.GetDefaultPass(), 8);
            //Variable temp is used to take out default password stored in file to make a comparison with new default password
            Password temp;
            ifstream file("ASM04.dat", ios::binary);
            if (file.is_open()) {
                file.read(reinterpret_cast<char*>(&temp), sizeof(temp));	//Read object from binary file
                file.close();
            }
            //Compare new and previous default password
            if (Array::IsEqual(temp.GetDefaultPass(), 8, p.GetDefaultPass(), 8) == true) {
                cout << "PASSWORD ALREADY EXIST IN FILE" << endl;
                system("pause");
                break;
            }
            //If user enter new default password, update it to binary file and reset vehicle
            else {
                ofstream file("ASM04.dat", ios::binary | ios::trunc);
                if (file.is_open()) {
                    file.write(reinterpret_cast<char*>(&p), sizeof(p));	//Write object to binary file
                    file.close();
                    cout << "DATA IS SAVED IN FILE" << endl;
                    system("pause");
                }
                cout << "THE VEHICLE WILL BE TURNED OFF TO RESET PASSWORD !!!" << endl;
                exit(0);
            }
        }
        else if (choice == "n" || choice == "N" || choice == "NO" || choice == "no") {
            break;
        }
    } while (true);
    system("cls");
}
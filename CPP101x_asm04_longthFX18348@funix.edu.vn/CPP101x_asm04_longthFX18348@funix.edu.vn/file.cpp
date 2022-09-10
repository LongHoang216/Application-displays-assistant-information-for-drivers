#include "file.h"
bool File::FileContainPass() {
    fstream file("ASM04.dat");
    if (file.is_open()) {
        file.seekg(0, ios::end);  //Check whether there is password in file or not 
        if (file.tellg() == 0) {   //If binary file is empty, announce for the driver
            file.close();
            return false;
        }
        else {
            file.close();
            return true;
        }
    }
    return 0;
}
bool File::FileContainSpeed() {
    Password p;
    ReadPassFromFile(p);
    streampos pos = sizeof(p);
    cout << pos << endl;
    fstream file("ASM04.dat");
    if (file.is_open()) {
        file.seekg(pos);  //Move cursor to the position of warning speed object 
        if (file.tellg() == 0) {   //If binary file does not have warning speed, announce for drivers to enter warning speeds
            file.close();
            return false;
        }
        else {
            file.close();
            return true;
        }
    }
}
void File::WritePassToFile(Password p) {
    //Erase and write new data to file each time user want to set default password
    ofstream file("ASM04.dat", ios::binary | ios::trunc);
    if (file.is_open()) {
        file.write(reinterpret_cast<char*> (&p), sizeof(p));	//Write object to binary file
        file.close();
    }
    else {
        cerr << "ERROR IN OPENING FILE" << endl;
        system("pause");
    }
}
void File::ReadPassFromFile(Password &p) {
    ifstream ifile1("ASM04.dat", ios::binary);
    if (ifile1.is_open()) {
        ifile1.read(reinterpret_cast<char*> (&p), sizeof(p));	//Write object to binary file
        ifile1.close();
    }
    else {
        cerr << "ERROR IN OPENING FILE" << endl;
        system("pause");
    }
}
void File::WriteSpeedToFile(WarningSpeed sp) {
    Password p;
    //The warning speed object need to be written after password
    //Each time user want to change the warning speed in file, the password data is not affected
    fstream file("ASM04.dat", ios::binary | ios::out | ios::in);
    if (file.is_open()) {
        file.seekp(64,ios::beg); //Move the cursor to the end of password object to enter warning speed object
        file.write(reinterpret_cast<char*> (&sp), sizeof(sp));
        file.close();
    }
    else {
        cerr << "ERROR IN OPENING FILE" << endl;
        system("pause");
    }
}
void File::ReadSpeedFromFile(WarningSpeed &sp) {
    Password p;
    fstream ifile1("ASM04.dat", ios::binary | ios::in | ios::out);
    if (ifile1.is_open()) {
        ifile1.seekg(64, ios::beg); //Move the cursor to the position of warning speed object to read 
        ifile1.read(reinterpret_cast<char*> (&sp), sizeof(sp));	
        ifile1.close();
    }
    else {
        cerr << "ERROR IN OPENING FILE" << endl;
        system("pause");
    }
}

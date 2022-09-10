#include "vehicle.h"

void Vehicle::Login() {
    Password pass;
    if (File::FileContainPass() == false) {
        cout << "EMPTY DATA !!! PLEASE SET DEFAULT PASSWORD" << endl;
        system("pause");
        pass.SetDefaultPass();
        File::WritePassToFile(pass);    //If file does not have password, write default password to file
    }
    //If binary file already contains default password, require user to enter password 
    //and make a comparison between default and user password
    system("cls");
    ReadPassFromFile(pass); //Take out default pass from file to arrange and print to the console
    cout << "ENTER PASSWORD TO UNLOCK VEHICLE" << endl;
    system("pause");
    pass.SetUserPass();
    system("cls");
    cout << "PASSWORD ENTERED BEFORE ARRANGING: ";
    pass.PrintUserPass();
    Algorithm::SelectionSort(pass.GetUserPass(), 8);    //Arrange user password before comparing by selection sort
    cout << "PASSWORD ENTERED AFTER ARRANGING: ";
    pass.PrintUserPass();
    cout << "Number of step of Selection Sort: " << Algorithm::SelectionSort_step << endl;

    cout << endl;

    cout << "DEFAULT-PASSWORD BEFORE ARRANGING: ";
    pass.PrintDefaultPass();
    Algorithm::BubbleSort(pass.GetDefaultPass(), 8);    //Arrange user password before comparing by bubble sort
    cout << "DEFAULT-PASSWORD AFTER ARRANGING: ";
    pass.PrintDefaultPass();
    cout << "Number of step of Bubble Sort: " << Algorithm::BubbleSort_step << endl;

    if (Array::IsEqual(pass.GetUserPass(), 8, pass.GetDefaultPass(), 8) == true) {   //Compare 2 password
        cout << "\n---> PASSWORD MATCHED" << endl;
        system("pause");
    }
    else {
        cout << "\n---> WRONG PASSWORD\nGOOD BYE !!!" << endl;
        exit(0);
    }
}
void Vehicle::ChangeGear() {
    cout << "\nHello " << kuser_name << endl;
    char choice;
    do {
        cout << "----MAIN MENU----" << endl;
        cout << "1. P: Parking mode" << endl;
        cout << "2. N: Neutral mode" << endl;
        cout << "3. R: Reverse mode" << endl;
        cout << "4. D: Drive mode" << endl;
        cout << "5. TURN OFF VEHICLE" << endl;
        cout << "Your choice: ";
        cin >> choice;
        if (isdigit(choice) == 0) {
            cout << "\nSyntax error !!!" << endl;
            cout << "Please enter again" << endl;
            system("pause");
            system("cls");
            ChangeGear();
        }
        choice = choice - '0';  //Convert character '0'-'9' to number 0 - 9
        switch (choice) {
        case 1:
            Parking();
            break;
        case 2:
            Neutral();
            break;
        case 3:
            // The user can only shift to R gear when the vehicle is standstill
            if (speed == 0) {
                speed = 7;
                Reverse();
            }
            else if (speed > 0 && gear == R) {
                Reverse();
            }
            else if (speed > 0 && gear == D) {
                system("cls");
                cout << "VEHICLE IS IN DRIVE MODE" << endl;
                cout << "PLEASE ENSURE THE VEHICLE IS STOPPED BEFORE SHIFTING TO R GEAR !!!" << endl;
                ChangeGear();
            }
            break;
        case 4:
            if (speed == 0) {
                speed = 7;
                Drive();
            }
            else if (speed > 0 && gear == D) {
                Drive();
            }
            else if (speed > 0 && gear == R) {
                system("cls");
                cout << "VEHICLE IS IN REVERSE MODE" << endl;
                cout << "PLEASE ENSURE THE VEHICLE IS STOPPED BEFORE SHIFTING TO D GEAR !!!" << endl;
                ChangeGear();
            }
            break;
        case 5:
            system("cls");
            cout << "YOUR VEHICLE IS TURNED OFF !!!" << endl;
            cout << "GOOD BYE !!!" << endl;
            break;
        }
    } while (choice > 5);
}
void Vehicle::Parking() {
    system("cls");
    if (speed >= 1) {
        cout << "PLEASE ENSURE THAT VEHICLE IS STOPPED AND THE SPEED IS 0 KM/H" << endl;
    }
    else if (speed == 0) {
        cout << "PARKING MODE: ON" << endl;
        cout << "Wheels: Blocked" << endl;
        cout << "PLEASE APPLY THE HANDBRAKE FOR SAFETY!!!" << endl;
    }
    ChangeGear();
}

void Vehicle::Neutral() {
    system("cls");
    if (speed >= 1) {
        cout << "PLEASE ENSURE THAT VEHICLE IS STOPPED AND THE SPEED IS 0 KM/H" << endl;
    }
    else if (speed == 0) {
        cout << "NEUTRAL MODE: ON" << endl;
        cout << "Wheels: Unblocked" << endl;
        cout << "PLEASE APPLY THE HANDBRAKE FOR SAFETY !!!" << endl;
    }
    ChangeGear();
}

void Vehicle::Reverse() {
    char pedals; //Used to change between Throttle and Brake pedal
    gear = R;
    do {
        system("cls");
        cout << "REVERSE MODE: ON" << endl;
        //The speed for R gear is 7 km/h when throttle pedal is released
        if (speed > 0 && speed < 7) {
            speed = 7;
        }
        cout << "YOUR VEHICLE IS REVERSING" << endl;
        cout << "CURRENT SPEED: " << speed << " km/h" << endl;
        if (speed > 20) {
            cout << "OVERSPEED !!! - YOU SHOULD DECREASE VEHICLE SPEED" << endl;
        }
        CheckSpeed();
        cout << "\nDRIVER EXPECTATION: " << endl;
        cout << "1. Accelerate" << endl;
        cout << "2. Decelerate" << endl;
        cout << "3. Brake" << endl;
        cout << "4. BACK TO MENU" << endl;
        cout << " >> ";
        cin >> pedals;
        if (isdigit(pedals) == 0) {
            cout << "\nSyntax error !!!" << endl;
            cout << "Please enter again" << endl;
            system("pause");
            system("cls");
            ChangeGear();
        }
        pedals = pedals - '0';
        switch (pedals) {
        case 1:
            speed += 5;
            break;
        case 2:
            speed -= 5;
            break;
        case 3:
            speed = 0;
            break;
        case 4:
            system("cls");
            ChangeGear();
            break;
        default:
            cout << "Wrong choice" << endl;
            cout << "Please enter again !!!" << endl;
            system("pause");
            system("cls");
            Reverse();
            break;
        }
    } while (pedals < 4);
}

void Vehicle::Drive() {
    char pedals; //Used to change between Throttle and Brake pedal
    gear = D;
    do {
        system("cls");
        cout << "DRIVE MODE: ON" << endl;
        //The speed for D gear is 7 km/h when throttle pedal is released
        if (speed > 0 && speed < 7) {
            speed = 7;
        }
        cout << "YOUR VEHICLE IS MOVING" << endl;
        cout << "CURRENT SPEED: " << speed << " km/h" << endl;
        if (speed > 60) {
            cout << "OVERSPEED !!! - YOU SHOULD DECREASE VEHICLE SPEED" << endl;
        }
        CheckSpeed();
        cout << "\nDRIVER EXPECTATION: " << endl;
        cout << "1. Accelerate" << endl;
        cout << "2. Decelerate" << endl;
        cout << "3. Brake" << endl;
        cout << "4. BACK TO MENU" << endl;
        cout << " >> ";
        cin >> pedals;
        if (isdigit(pedals) == 0) {
            cout << "\nSyntax error !!!" << endl;
            cout << "Please enter again" << endl;
            system("pause");
            system("cls");
            ChangeGear();
        }
        pedals = pedals - '0';
        switch (pedals) {
        case 1:
            speed += 5;
            break;
        case 2:
            speed -= 5;
            break;
        case 3:
            speed = 0;
            break;
        case 4:
            system("cls");
            ChangeGear();
            break;
        default:
            cout << "Wrong choice" << endl;
            cout << "Please enter again !!!" << endl;
            system("pause");
            system("cls");
            Drive();
            break;
        }
    } while (pedals < 4);
}

void Vehicle::SafeDistanceWarning() {
    WarningSpeed sp;
    fstream file1("safe_distance_speed.dat");
    if (File::FileContainSpeed() == false) {    //Announce for drivers if file does not contain warning speed object
        cout << "EMPTY DATA !!! PLEASE SET SAFE DISTANCE WARNING SPEEDS" << endl;
        system("pause");
        
    }
    sp.SetWarningSpeed();   //Get speeds from user
    WarningSpeed temp;
    ReadSpeedFromFile(temp); //Take out te speeds in the file to compare with user input
    if (Array::IsEqual(sp.GetSpeed(), 3, temp.GetSpeed(), 3) == false) {    //Announce for driver to know whether the data is new or already exist
        cout << "NEW DATA IS UPDATED TO FILE !!!" << endl;
        system("pause");
    }
    else {
        cout << "DATA ALREADY EXIST IN FILE" << endl;
        system("pause");
    }
    WriteSpeedToFile(sp);   //Write speed range array to binary file
    //Check if 3 level speed ranges are different and higher than 0
    system("cls");
    sp.PrintWarningSpeed();
    system("pause");
    system("cls");
}
void Vehicle::ChangeWarningSpeed() {
    do {
        system("cls");
        cout << "DO YOU WANT TO CHANGE SAFE WARNING SPEED? (y/n)" << endl;
        string choice;
        cout << "Your choice: ";
        cin >> choice;
        if (choice == "y" || choice == "Y" || choice == "yes" || choice == "YES") {
            Vehicle::SafeDistanceWarning(); //Enter speed range again when user want to change speeds
            break;
        }
        else if (choice == "n" || choice == "N" || choice == "NO" || choice == "no") {
            break;
        }
    } while (true);
    system("cls");
}
void Vehicle::CheckSpeed() {
    WarningSpeed warning_speed;
    ReadSpeedFromFile(warning_speed);
    if (speed > 0 && speed <= warning_speed.GetElement(0)) {
        cout << "KEEP A MINIMUM DISTANCE AT 20m WITH OTHER VEHICLES" << endl;
    }
    else if (speed > warning_speed.GetElement(0) && speed <= warning_speed.GetElement(1)) {
        cout << "KEEP A MINIMUM DISTANCE AT 55m WITH OTHER VEHICLES" << endl;
    }
    else if (speed > warning_speed.GetElement(1) && speed <= warning_speed.GetElement(2)) {
        cout << "KEEP A MINIMUM DISTANCE AT 70m WITH OTHER VEHICLES" << endl;
    }
    else if (speed > warning_speed.GetElement(2)) {
        cout << "KEEP A MINIMUM DISTANCE AT 100m WITH OTHER VEHICLES" << endl;
    }
}
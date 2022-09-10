#include "vehicle.h"
using namespace std;

int main() {
	Vehicle my_vehicle;
	my_vehicle.Login();
	my_vehicle.ChangeDefaultPass();
	my_vehicle.SafeDistanceWarning();
	my_vehicle.ChangeWarningSpeed();
	my_vehicle.ChangeGear();
	return 0;
}
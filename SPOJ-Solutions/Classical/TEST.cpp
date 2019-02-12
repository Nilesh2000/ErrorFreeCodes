//Header Files
#include <iostream>

using namespace std;

int main() //Main Function
{
	int intNum = 0;
	cin >>intNum; //Input The First Number
	while (intNum != 42) 
	{
		cout << intNum << "\n"; //Display Inputted Number
		cin >> intNum; //Continue To Input Numbers Until You Encounter 42 
	}
	return 0;
}

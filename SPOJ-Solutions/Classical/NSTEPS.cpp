//Header Files
#include <iostream>

using namespace std;

int main() //Main Function
{
	int t, x, y;
	cin >>t; //Input Number Of Test Cases
	for(int i=1;i<=t;i++)
	{
		cin >>x >>y; //Input X And Y Coordinates
		if(x==y || x==y+2) 
		{
			if(x%2==0)
			{
				cout <<x+y <<endl;
			}
			else
				cout <<x+y-1 <<endl;
		}
		else
			cout <<"No Number" <<endl;
	}
	return 0;
}
//Multiple Sources Used

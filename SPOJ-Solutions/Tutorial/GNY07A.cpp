//Header Files
#include<iostream>
#include<string.h>

using namespace std;

int main() //Main Function
{
	int n,a;
	char s[90];
	cin>>n; //Input Number Of String Cases
	for(int j=1;j<=n;j++)
	{
		cin >>a >>s; //Input Index Of Letter To Be Deleted And String
		for(int i=a-1;i<strlen(s);i++)
			s[i]=s[i+1];
		cout <<j <<" " <<s <<endl; //Print Index Of Deleted Character And The Mispelled String
	}
	return 0;
}

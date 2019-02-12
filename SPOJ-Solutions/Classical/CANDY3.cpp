//Header Files
#include <iostream>

using namespace std;

int main() //Main Function
{
	long  long Ans, t, n, Candies;
	cin >>t; //Input Number Of Test Cases
	cout <<endl;
	for(int j=0;j<t;j++)
	{
		cin >>n; //Input Number Of Children
		long long Sum=0;
		for(int i=0;i<n;i++)
		{
			cin >>Candies; //Input Candies Bought By Each Child 
			Sum=(Sum+Candies)%n;
		}
		if(Sum%n==0) //If Condition To Check If Candies Can Be Divided Equally
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
//Source
//https://codegeeksblog.wordpress.com/2013/06/02/spoj-candy3/

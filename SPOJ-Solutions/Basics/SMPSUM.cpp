//Header Files
#include <iostream>

using namespace std;

long int SumOfSquares(int n) 
{
	return n*(n+1)*(2*n+1)/6; //Reurns The Sum Of The First n^2 Terms
}

int main() //Main Function
{
	int a, b;
	cin >>a >>b; //Input Terms a And b
	cout <<SumOfSquares(b)-SumOfSquares(a-1); //Display Required Output
	return 0;
}
//Source
//https://github.com/fjozsef/SPOJ/blob/master/SMPSUM/smpsum.cc

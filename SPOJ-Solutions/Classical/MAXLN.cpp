//Header Files
#include <iostream>

using namespace std;

int main() //Main Function 
{
	long long n, t, k;
	cin >>t; //Input Number Of Test Cases
	/*
	It is to be noticed that the triangle is a right angled triangle because it has a base which is the diameter of the 
	circle. This means that BC^2=AC^2 + AB^2.Hence,  we can add and subtract one AC which will not change the equation. 
	BC^2=AC^2 + AB^2 -AC + AC  . Let us write BC^2 (BC is the diameter)  as (2r)^2 which will be 4r^2 and let’s group the right part 
	properly. Thus,
	4r^2= (AB^2+AC)+AC^2-AC
	AB^2+AC= 4r^2 -AC^2+AC which can be considered as a function f(AC) where AC is the unknown variable. We need to find the maximum
	value of function f(AC) which can be done with differentiation . f ‘(AC)= 0 -2*AC +1 .
	-2*AC+1=0 
	=> AC=1/2  
	=> We can easily notice that the function increases up to f(1/2) and then it decreases so the maximum value is at
	  AC=1/2 which gives the full answer of 4*r*r -1/4+1/2 =4*r*r+1/4
	*/
	for(k=1;k<=t;k++)
	{
		cin >>n; //Input Radius Of Semi-Circle
		cout <<"Case " <<k <<": " <<4*n*n <<".25" <<endl; //Display Output
	}
	return 0;
}
//Source 
//http://xoptutorials.com/index.php/2017/01/01/spojmaxln/

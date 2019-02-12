//Header Files
# include <iostream>

using namespace std;

int Rev_Num(int n) //Function To Reverse A Number
{
	int rev=0, rem; //rem=Remainder After Dividing Number By 10, rev=Variable For Storing The Reversed Number
	while(n!=0)
	{
		rem=n%10; //Calculation Of Remainder After Dividing By 10
		rev=rev*10+rem; //Adding rem to rev*10
		n/=10; //Dividing n By 10 
	}
	return rev; //Returning Reversed Number Back To Main
}

int main() //Main Function
{
    int n;
    cin >>n; //Input Number Of Test Cases
    int Num1[n], Num2[n], Rev_Sum[n], Final_Sum[n];
    for(int i=0;i<n;i++)
    {
        cin >>Num1[i] >>Num2[i]; //Input Test Cases
        Rev_Sum[i]=Rev_Num(Num1[i])+Rev_Num(Num2[i]); //Reversing Entered Numbers
        Final_Sum[i]=Rev_Num(Rev_Sum[i]); //Reversing The Sum Of The Reversed Numbers
    }
    for(int i=0;i<n;i++)
        cout <<Final_Sum[i] <<endl; //Printing Output
    return 0;
}

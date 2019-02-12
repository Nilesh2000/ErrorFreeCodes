//Header Files
# include <iostream>

using namespace std;

int main() //Main Function 
{
    int n, k, Num=0;;
    cin >>n >>k; //Input Number Of Test Cases And Divisor
    int Arr[n];
     for(int i=0;i<n;i++)
     {
         cin >>Arr[i]; //Input Each Element Of Array
         if(Arr[i]%k==0) //If Condition To Check Whether Arr[i] Is Divisible By k.
            Num++;
     }
     cout <<Num; //Display The Count Of Numbers Divisible By k
     return 0;
}

//Header Files
# include <iostream>

using namespace std;

int main() //Main Function
{
    int n;
    cin >>n; //Input Number Of Test Cases
    long long Arr[n], Res[n];
     for(int i=0;i<n;i++)
     {
        cin >>Arr[i]; //Input Number Of Level Triangles In Each Case
         
         if(Arr[i]%2==0) //If Condition To Check Whether The Level Triangles Is An Odd Number
          Res[i]=((Arr[i])*(Arr[i]+2)*(2*Arr[i]+1))/8;
         else
           Res[i]=(((Arr[i])*(Arr[i]+2)*(2*Arr[i]+1))-1)/8;
     }
     for(int i=0;i<n;i++)
        cout <<Res[i] <<endl; //Display Number Of Triangles In Each Case
     return 0;
}
//Source
//https://www.spoj.com/problems/TRICOUNT/
//note there is different formula for even and odd values of N (Comment Box)

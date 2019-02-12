//Header Files
# include <iostream>

using namespace std;

int main() //Main Function
{
    int n;
    cin >>n; //Input Number Of Rows Of The Pattern
     for(int i=1;i<=n;i++) //Loop To Print Rows
     {
         for(int j=i;j>=1;j--) //Loop To Print Cols
         {
             cout <<j <<" ";
         }
         cout <<endl;
     }
     return 0;
}

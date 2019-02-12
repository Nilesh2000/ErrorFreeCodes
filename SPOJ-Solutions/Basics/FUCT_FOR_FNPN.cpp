//Header Files
# include <iostream>

using namespace std;

int main()
{
    int n;
    long long Num;
    cin >>n; //Input Number Of Test Cases
    while(n--)
    {
        cout <<endl;
        cin >>Num; //Input The Number To Print The First n Positve Numbers
        
          if(Num>0) //If Condition To Check If The Entered Number Is Greater Than 0.
          {
            for(int i=1;i<=Num;i++) //Loop To Print First n Positve Numbers
             cout <<i <<" ";
          }
          else 
            cout <<"invalid" <<endl;
    }
    return 0;
}

//Header Files
# include <iostream>

using namespace std;

int main()
{
    int n;
    cin >>n; //Input Number Of Test Cases
    int Rows[n], Cols[n];
     for(int i=0;i<n;i++)
        cin >>Rows[i] >>Cols[i]; //Input Number Of Rows And Cols For Each Test Case
    
     for(int a=0;a<n;a++) //Loop For Each Test Case
     {
         for(int i=0;i<Rows[a];i++) //Loop For Printing The Rows
         {
             for(int j=0;j<Cols[a];j++) //Loop For Printing Cols
             {
                 if(i==0 || i==Rows[a]-1 || j==0 || j==Cols[a]-1) //If Condition To Check Whether To Print * or .
                    cout <<"*";
                 else
                    cout <<".";
             }
             cout <<endl;
         }
         if(n>0) //Insert A Newline After Printing Output Of Each Test Case.
            cout <<endl;
     }
     return 0;
}

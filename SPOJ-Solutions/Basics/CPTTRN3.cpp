//Header Files
# include <iostream>

using namespace std;

int main() //Main Function
{
    int n;
    cin >>n; //Input Number Of Test Cases
    int Rows[n], Cols[n];
     for(int i=0;i<n;i++)
     {
       cin >>Rows[i] >>Cols[i]; //Input Number Of Rows And Cols For Each Test Case
         //Modify Number Of Rows And Cols According To The Required Output
       Rows[i]=(Rows[i]+1)+(Rows[i]*2); 
       Cols[i]=(Cols[i]+1)+(Cols[i]*2);
     }
     for(int a=0;a<n;a++) //Loop For Each Test Case
     {
         for(int i=0;i<Rows[a];i++) //Loop For Printing The Rows
         {
             for(int j=0;j<Cols[a];j++) //Loop For Printing Cols
             {
                 if(i%3==0 || j%3==0) //If Condition To Check Whether To Print * or .
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
//Source
//https://www.spoj.com/problems/CPTTRN3/ (Comment Box)

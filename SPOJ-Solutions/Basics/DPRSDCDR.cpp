//Header Files
# include <iostream>

using namespace std;

int main() //Main Function
{
    int n;
    cin >>n; //Input Number Of Test Cases
    int CT, Lab_Reports, Time, Report, Class;
     while(n--)
     {
         //Input Time Taken For CT's, Lab Reports, CT Preparation, Lab Report Writing And Attending Classes  
         cin >>CT >>Lab_Reports >> Time >>Report >>Class; 
         int Sum=CT+Lab_Reports+Time+Report+Class; //Compute Total Sum Of Time Taken In Each Of The Activities
         
          if(Sum>=14) //If Condition To Check Whether Total Time Exceeds 14 Hours 
            cout <<"Hotash" <<endl;
          else
            cout <<"Khushi" <<endl;
     }
     return 0;
}

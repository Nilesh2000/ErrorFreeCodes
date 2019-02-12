//Header Files
#include <iostream>

using namespace std;

int main() //Main Function
{
   int t, ng, nm;
   cin >>t; //Input Number Of Test Cases
   while(t--)
   {
      cin >>ng >>nm; //ng=Number Of Monsters In Godzilla's Army ,nm=Number Of Monsters In MechaGodzilla's Army
      int ngArr, nmArr, ngLarge=-1, nmLarge=-1; //ngLarge=Strongest Monster In Godzilla's Army, nmLarge=Strongest Monster In
                                                //MechaGodzilla's Army
       for(int i=0;i<ng;++i)
       {
         cin >>ngArr; //Input Strength Of Each Monster In Godzilla's Army 
          if(ngArr>ngLarge)
            ngLarge=ngArr;
      }
      for(int i=0;i<nm;++i)
      {
         cin >>nmArr; //Input Strength Of Each Monster In MechaGodzilla's Army 
         if(nmArr>nmLarge)
            nmLarge=nmArr;
      }
      
      //Printing The Army Whose Which Has The Strongest Monster
      
      if(ngLarge>=nmLarge) //If Condition To Compare Strength Of Strongest Monster In Each Of The Two Armies
        cout <<"Godzilla" <<endl;
      else
        cout <<"MechaGodzilla" <<endl;
   }
   return 0;
}
//Source
//http://code.cloudkaksha.org/spoj/spoj-army-solution

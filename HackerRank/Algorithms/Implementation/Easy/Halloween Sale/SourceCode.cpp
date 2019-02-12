//Header Files
# include <iostream>

using namespace std;

int main() //Main Function
{
    int p, d, m, s, Games=0;
    cin >>p >>d >>m >>s; //Input Current Price, Difference In Price After Every Purchase, Minimum Price And Total Amount To Be Spent
     while(s>=p)
     {
         s-=p;
         Games++;
          if(p-d>=m) //If Condition To Check Whether The Difference Between Current Price And Difference In Price After Every Purchase Is  
                     //Greater Than Or Equal To Minimum Price    
              p-=d;
         else
             p=m;
     }
    cout <<Games; //Display Output
    return 0;
}

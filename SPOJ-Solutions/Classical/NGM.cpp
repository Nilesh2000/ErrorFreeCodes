//Header Files
#include <iostream>

using namespace std;

int main() //Main Function
{
 int n;
 cin>>n; //Input The Positive Integer From Which The Game Is Started.
  
  if(n%10==0) //If Condition To Check Whether Entered Number Is Divisible By 10. If So, Then Player 2 Wins. 
    cout <<2 <<endl;
  else
    cout <<1 <<endl <<n%10 <<endl; /*Else Player 1 Wins (n%10 Will Be The Winning Move Because The Players Can Subtract Only From Numbers 
                                   (1 To 9)*/
return 0;
}
//Source
//https://www.quora.com/How-do-I-solve-SPOJ-com-NGM-A-Game-With-Numbers

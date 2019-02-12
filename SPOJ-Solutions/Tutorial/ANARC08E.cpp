//Header Files
#include <iostream>

using namespace std;

int main() //Main Function
{
	int Team1, Team2;
	while(1)
	{
         cin >>Team1 >>Team2; //Input Test Cases
      	  if(Team1==-1 && Team2==-1) //Check If Input Is To Be Terminated 
			break;
	  else if(Team1==1 || Team2==1) //If Condition To Display Sum If Team1=Team2=1
			cout <<Team1 <<"+" <<Team2 <<"=" <<Team1+Team2 <<endl;
	   else //Else Condition to Check If Team1 Is Not Equal To Team2
			cout<<Team1 <<"+" <<Team2 <<"!=" <<Team1+Team2 <<endl;
	}
	return 0;
}

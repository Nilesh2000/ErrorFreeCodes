# include <iostream>
# include <cstring>
using namespace std;
int main()
{
	string s;
	int Flag=0;
	cin >>s;
	 for(int i=0;i<s.length();i++)
	  {
	  	if(s[i]=='H' || s[i]=='Q' || s[i]=='9')
	     {
	     	Flag=1;
	     	cout <<"YES" <<endl;
	     	 break;
	     }
	    else 
	     continue;
	  }
	 if(Flag==0)
	  cout <<"NO" <<endl;
}

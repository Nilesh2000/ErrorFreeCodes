# include <iostream>
# include <cstring>
using namespace std;
int main()
{
	long long n;
	cin >>n;
	int Cnt=0;
	 while(n!=0)
	  {
	  	if(n%10==4 || n%10==7)
	  	 Cnt++;
	   n/=10;	
	  }
	  if(Cnt==4 || Cnt==7)
	   cout <<"YES" <<endl;
	  else
	   cout <<"NO" <<endl;
	return 0;
}

# include <iostream>
using namespace std;
int main()
{
	int k, w;
	long long n, Total;
	cin >>k >>n >>w;
	 for(int i=1;i<=w;i++)
	  {
	  	Total+=(i*k);
	  }
	 if(Total>n)  
      cout <<Total-n <<endl;
     else
      cout <<0 <<endl;
    return 0;
}

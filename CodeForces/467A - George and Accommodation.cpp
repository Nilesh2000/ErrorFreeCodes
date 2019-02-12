# include <iostream>
using namespace std;
int main()
{
	int p, q, n, Cnt=0;
	cin >>n;
	 while(n--)
	  {
	  	cin >>p >>q;
	  	 if(q-p>=2)
	  	  Cnt++;
	  }
	cout <<Cnt <<endl;
	return 0;
}

# include <iostream>
using namespace std;
int main()
{
	int n, Max=0, Count=0;
	cin >>n;
	int a[n], b[n];
	 for(int i=0;i<n;i++)
	  {
	   cin >>a[i] >>b[i];
	   Count-=a[i];
	   Count+=b[i];
	    if(Count > Max)
	     {
	     	Max = Count;
	     }
	  }
	cout <<Max <<endl;
	return 0;
}

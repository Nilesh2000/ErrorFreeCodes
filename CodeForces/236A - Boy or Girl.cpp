# include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >>s;
	int Cnt=1;
	sort(s.begin(), s.end());
	 for(int i=1;i<s.length();i++)
	  {
	  	if(s[i]==s[i-1])
	  	 {
	  	 	continue;
	  	 }
	  	else
	  	 {
	  	 	Cnt++;
	  	 }
	  }
	 if(Cnt%2)
	  cout <<"IGNORE HIM!" <<endl;
	 else
	  cout <<"CHAT WITH HER!" <<endl;
	return 0;
}

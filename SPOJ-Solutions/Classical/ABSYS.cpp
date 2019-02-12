//Header Files
# include <iostream>
# include <cstdio>
# include <string>

using namespace std;

int MMstoi(string str) //Function To Convert String To Int
{
	int num=0;
	for(int i=0;i<str.length();i++)
	{
		num=num*10+(int)(str[i]-48); //ASCII Code Of '0' is 48.
	}
	return num; //Returning String Converted To Num Back To Main
}

//Main Function
int main()
{
	int t;
	cin>>t; //Input Number Of Test Cases
	while(t--)
	{
		long int a, b, c;
		string str="machula"; //String To Be Checked
		string str1,str2,str3;
		char ch1,ch2;
		cin >> str1 >> ch1>> str2 >> ch2>> str3; //Input Test Cases
		 
	//Find Function Is Use To Search For A Particular String In A String
		if(str1.find(str)!=-1) //If Condition Is True
		 {
		  b=MMstoi(str2);
		  c=MMstoi(str3);
		  a=c-b;
		 }
		
		else if(str2.find(str)!=-1) //If Condition Is True
		{
		 a=MMstoi(str1);
		 c=MMstoi(str3);
		 b=c-a;
		}
		
		else //Else Condition
		{
		 a=MMstoi(str1);
		 b=MMstoi(str2);
		 c=b+a;
		}
		
		cout <<a <<" " <<ch1 <<" " <<b <<" " <<ch2 <<" " <<c <<endl; //Printing Output
	}
	return 0;
}
//Source
//https://www.snip2code.com/Snippet/1019207/SPOJ-SOLUTION-Anti-Blot-System



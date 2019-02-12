# include <iostream>
using namespace std;
int main()
{
    int Hours, Minutes;
    cin >>Hours >>Minutes;
    char *count[]= {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",                     "eleven", "twelve", "thirteen", "fourteen", "quater", "sixteen", "seventeen",                     "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three",                     "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight",                       "twenty nine"};
    
    if(Minutes==0)
        cout <<count[Hours-1] <<" o' clock";
    else if(Minutes>30)
    {
        if(Minutes==59)  
            cout <<count[Minutes-1] <<" minutes to " <<count[Hours];
        else if(Minutes==45)
            cout <<"quarter to " <<count[Hours];
        else
            cout <<count[60-Minutes-1] <<" minutes to " <<count[Hours];       
    }
    else if(Minutes<30)
    {
        if(Minutes==1)           
            cout <<count[Minutes-1] <<" minute past " <<count[Hours-1];   
        else if(Minutes==15)
            cout <<"quarter past " <<count[Hours-1];   
        else
            cout <<count[Minutes-1] <<" minutes past " <<count[Hours-1];   
    }
    else
        cout <<"half past " <<count[Hours-1];
    return 0;
}

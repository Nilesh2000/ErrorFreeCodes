//Header Files
# include <iostream>
# include <string>

using namespace std;

int main() //Main Function
{
    string Str;
    int Num_Sqr=0, c=1;
    cin >>Str; //Input Number To Check If It Is A Happy Number
    
    for(int i=0;Str[i]!='\0';i++) //Loop To Compute The Square Of Each Digit In The Entered Number
         Num_Sqr+=(Str[i] - 48)*(Str[i]-48); 
    
    while(Num_Sqr>9)
    {
        int x=0;
        while(Num_Sqr>0) //Loop To Ensure That The Result Of Each Num_Sqr After Breaking The Number Is Greater Than 0
        {
            x+=(Num_Sqr%10)*(Num_Sqr%10); //Compute The Square Of Each Digit After Breaking Each Digit Of The Number
            Num_Sqr/=10;
        }
        Num_Sqr=x;
        c++;
    }
    if(Num_Sqr==1) //If Condition To Check If Result Of Num_Sqr After Leaving The Loop Is 1
       cout <<c;
    else
        cout <<"-1";
    return 0;
}
//Source
//http://spoj-sus.blogspot.com/2015/08/hpynos.html

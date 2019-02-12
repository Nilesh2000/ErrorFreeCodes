# include <iostream>
using namespace std;
long long DigitCount(long long Num)
{
    long long Count=0;
    while(Num)
    {
        Count++;
        Num/=10;
    }
    return Count;
}
long long SplitNumber(long long Num)
{
    long long Temp=1;
    while(Num)
    {
        Temp*=10;
        Num--;
    }
    return Temp;
}
int main()
{
    long long p, q;
    int Flag=0;
    cin >>p >>q;
     for(long long i=p;i<=q;i++)
      {
        long long a, b, Digit, Sqr;
        Sqr=i*i;
        Digit=DigitCount(Sqr);
        Digit-=(Digit/2);
        a=Sqr/SplitNumber(Digit);
        b=Sqr%SplitNumber(Digit);
        if((a+b) == i)
        {
            Flag=1;
            cout <<i <<" ";
        }    
    }
    if(Flag==0)
        cout <<"INVALID RANGE";
    return 0;
}

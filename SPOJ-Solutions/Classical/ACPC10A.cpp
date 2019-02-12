//Header Files
# include <iostream>
# include <math.h>

using namespace  std;

int main() //Main Function
{
    int a, b, c; //a=First Term, b=Second Term, c=Third Term
     cin >>a >>b >>c; //Input Of The Three Terms
     while(a || b || c)
     {
          if(b-a==c-b) //If Condition For Checking If Sequence Is In AP
            cout <<"AP " <<a+(3*(b-a)) <<endl;
         else if(b/a==c/b) //If Condition For Checking If Sequence Is In GP
            cout <<"GP " <<a*pow((b/a),3) <<endl;
             cin >>a >>b >>c; //Input Of The Three Terms. Input Ends When a=b=c=0
     }
     return 0;
}

//Source
//https://codegeeksblog.wordpress.com/2013/06/01/spoj-acpc10a-whats-next/

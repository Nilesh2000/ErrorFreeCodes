//Header Files
# include <iostream>

using namespace std;

int main(void) //Driver Function
{
    int a, b, Div, Rem, Count = 0;
    cin >> a >> b;
    Count += a; //Increment count of hours initially ny number of new candles

      while(a >= b) //While condition until a/b is equal to zero, that is, nothing but the condition until a >= b
                    //is true.
        {
          Div = a / b;
          Rem = a % b;
          Count += Div; //Increment Number of hours by division of number of burnt out candles with number of burnt out
                            //candles required to make a new candle.
          a = Div + Rem; //Remainder is necessary because a will not always be divisible by b
        }
    cout << Count << endl;
    return 0;
}
//End Of Program
//https://codeforces.com/blog/entry/46853
//Refer above link for an O(1) solution

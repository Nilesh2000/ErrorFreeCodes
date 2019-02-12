//Header Files
# include <iostream>

using namespace std;

int main(void) //Driver Function
{
    int Limak, Bob;
    cin >> Limak >> Bob;
      for(int i = 1 ; ; i++)
        {
            Bob *= 2;
            Limak *= 3;
              if(Limak > Bob)
                {
                    cout << i;
                     break;
                }
        }
    return 0;
}
//End Of Program

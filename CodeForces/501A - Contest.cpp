# include <iostream>
using namespace std;
int main(void)
{
    long a, b, c, d;
    cin >> a >> b >> c >> d;
    int Misha = max( 3 * a / 10, a - (a * c) / 250);
    int Vasya = max( 3 * b / 10, b - (b * d) / 250);
        if(Misha > Vasya)
        {
                cout << "Misha" << endl;
        }
        else if(Vasya > Misha)
        {
                cout << "Vasya" << endl;
        }
        else
        {
                cout << "Tie" << endl;
        }
    return 0;
}

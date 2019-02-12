//Header Files
# include <iostream>
# include <cmath>

using namespace std;

int main(void) //Driver Function
{
    double Radius, x, y, x1, y1;
    cin >> Radius >> x >> y >> x1 >> y1;
    double Dist = sqrt(pow( ( x - x1 ), 2 ) + (pow ( ( y - y1 ), 2 )) );
    cout << ceil(Dist / (2 * Radius )) ;
    return 0;
}
//End Of Program
//Use double instead of float because the range of float does not suffice for this program.
//Refer to https://codeforces.com/blog/entry/15975 for a beautiful explaination

# include <iostream>
using namespace std;
int main()
{
    int d1, d2, m1, m2, y1, y2, Fine=0;
    cin >> d1 >> m1 >> y1;
    cin >>d2 >> m2 >> y2;
    if(d1>d2 && m1==m2 && y1==y2)
     Fine=15*(d1-d2);
    else if(m1>m2 && y1==y2)
     Fine=500*(m1-m2);
    else if(y1 > y2)
      Fine=10000;
    cout <<Fine;
    return 0;
}

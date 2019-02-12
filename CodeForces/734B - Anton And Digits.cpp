//Header Files
# include <iostream>

using namespace std;

int main(void) //Driver Function
{
    int k2, k3,k5, k6, Max_Num = 0;
    cin >> k2 >> k3 >> k5 >> k6;
    int min256 = min(k2, min(k5, k6)); //Finding which number among k2, k5, k6 has the least count
    Max_Num += min256 * 256; //Incrementing by min256*256
    int min32 = min(k2 - min256, k3); //Finding which number among k2-min256 and k3 has least count
    Max_Num += min32 * 32; //Incrementing by min32*32
    cout << Max_Num << endl;
    return 0;
}
//End Of Program

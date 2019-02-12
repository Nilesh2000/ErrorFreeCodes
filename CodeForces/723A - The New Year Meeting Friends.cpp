//Header Files
# include <iostream>

using namespace std;

//In this program, one number will always be the average of the other two numbers.
int main(void) //Driver Function
{
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    cout << max(x1, max(x2, x3)) - min(x1, min(x2, x3)) << endl;
    return 0;
}
//End Of Program
//To solve this problem you need to understand that friends must meet in the middle point of the given points, so friends
//who live in the leftmost and in the rightmost points must go to the middle point, Because of that the answer equals
//to max(x1, x2, x3) - min(x1, x2, x3).

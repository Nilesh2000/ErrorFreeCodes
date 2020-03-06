#include <iostream>

using namespace std;

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod)
{
    if (n == 1)
    {
        cout << "\nMove disk 1 from rod " << fromRod << " to " << toRod;
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    cout << "\nMove disk " << n << " from rod " << fromRod << " to rod " << toRod;
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main()
{
    int n;
    cout << "\nEnter the number of disks : ";
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}

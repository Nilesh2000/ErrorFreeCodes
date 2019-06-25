# include <iostream>
# include <string.h>

using namespace std;

int sieveOfEratosthenes(int n)
{
    bool Prime[n + 1]; //Define a boolean variable Prime of size n+1. Size is n+1 because it consists of elements from 0 to n.
    memset(Prime, true, sizeof(Prime));
    for(int i = 2 ; i * i <= n ; i++)
    {
        if(Prime[i] == true)
        {
            for(int j = i * i ; j <= n ; j+=i)
            {
                Prime[j] = false;
            }
        }
    }
    for(int i = 2 ; i <= n ; i++)
    {
        if(Prime[i])
        {
            cout << i << " ";
        }
    }
}

int main(void)
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    cout << "\nPrime numbers from 1 to " << n << " are:-\n";
    sieveOfEratosthenes(n);
    cout << "\n";
    return 0;
}

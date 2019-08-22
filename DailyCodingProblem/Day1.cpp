//Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
# include <iostream>
# include <unordered_set>

using namespace std;

void printPair(int A[], int Sum, int n)
{
    unordered_set <int> S;
    for(int i = 0 ; i < n ; i++)
    {
        int Temp = Sum - A[i];
        if(S.find(Temp) != S.end())
        {
            cout << "The pairs are " << A[i] << " and " << Temp << "." << endl;
        }
        S.insert(A[i]);
    }
}

int main(void)
{
    int Arr[] = {9, 10, 8, 7, 5, 6};
    int Sum = 17;
    int Size = sizeof(Arr) / sizeof(Arr[0]);
    printPair(Arr, Sum, Size);
    return 0;
}

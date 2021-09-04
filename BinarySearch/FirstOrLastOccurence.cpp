#include <iostream>
#include <vector>

using namespace std;

int firstAndLastOccurence(vector<int> V, int x, bool firstSearch)
{
    int n = V.size();
    int Low = 0, High = n - 1, Result = -1;

    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;
        if (x == V[Mid])
        {
            Result = Mid;
            if (firstSearch)
                High = Mid - 1;
            else
                Low = Mid + 1;
        }
        else if (x < V[Mid])
            High = Mid - 1;

        else if (x > V[Mid])
            Low = Mid + 1;
    }
    return Result;
}

void displayIndex(int Flag)
{
    if (Flag != -1)
        cout << "\nFirst / Last Occurence Of Element Found At Index " << Flag << endl;
    else
        cout << "\nElement Not Found.\n";
}

int main(void)
{
    vector<int> V = {1, 1, 3, 3, 5, 5, 5, 5, 5, 9, 9, 11};
    int x = 5;

    cout << firstAndLastOccurence(V, x, true) << '\n';
    cout << firstAndLastOccurence(V, x, false);

    return 0;
}

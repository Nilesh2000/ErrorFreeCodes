//Given a list of numbers and a number k, return whether any two numbers from the list add up to k. Also, return their respective indices.
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> printPair(vector<int> &Num, int Sum)
{
    //An unordered map to map the the key - value pair where key is the element in the vector and value is it's index.
    unordered_map<int, int> M;
    vector<int> Res; //Vector to store indices.

    for (int i = 0; i < Num.size(); i++) //Traverse the whole vector
    {
        int numberToFind = Sum - Num[i];
        if (M.find(numberToFind) != M.end())
        {
            Res.push_back(M[numberToFind] + 1);
            Res.push_back(i + 1);
            //Incrementing by 1 since vector indices start at 0.
            cout << Num[i] << " " << numberToFind << " ";
        }
        M[Num[i]] = i; //If element is not found, insert it into the map.
    }
    return Res;
}

int main(void)
{
    vector<int> V = {9, 10, 8, 7, 5, 6};
    int Sum = 17;
    vector<int> R = printPair(V, Sum);
    cout << "\n";
    for (auto it = R.begin(); it != R.end(); it++)
        cout << *it << " ";
    return 0;
}
//End of program

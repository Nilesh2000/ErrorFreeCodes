//Given an array of n integers, print all the elements of the list which occur more than once in the list.
# include <iostream>
# include <unordered_set>

using namespace std;

void findDuplicates(int Arr[], int n)
{
    //No element can be present twice in an unordered set, that is no duplicates are allowed.
    unordered_set <int> Set;
    unordered_set <int> dupSet;
    for(int i = 0 ; i < n ; i++)
    {
        if(Set.find(Arr[i]) == Set.end())
        {
            Set.insert(Arr[i]);
        }
        else
        {
            dupSet.insert(Arr[i]);
        }
    }
    cout << "\nThe duplicates are : ";
    unordered_set <int> ::iterator it;
    for(it = dupSet.begin() ; it != dupSet.end() ; it++)
    {
        cout << *it << " ";
    }
}

int main(void)
{
    int Arr[] = {3, 4, 5, 2, 9, 1, 2, 4, 3, 5, 11};
    int Size = sizeof(Arr) / sizeof(Arr[0]);
    findDuplicates(Arr, Size);
    return 0;
}

/*
Given number of pages in n different books and m students.
The books are arranged in ascending order of number of pages.
Every student is assigned to read some consecutive books.
The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

Explanation:
Let V[] = {12, 34, 67, 90} and numStudents = 2

There are 2 students. Books can be distributed in following fashion:-
  1) [12] = 12 and [34, 67, 90] = 191 (Max : 191)
  2) [12, 34] = 46 and [67, 90] = 157 (Max : 157)
  3) [12, 34, 67] = 113 and [90] = 90 (Max : 113)
We have to minimize the largest number of pages a student can read. Thus, we have to return 113.

APPROACH:
1. The question uses Binary Search algorithm. Let N be the number of books.
2. The minimum number of pages which a student will have to read is the largest element in the array. (when N = numStudents)
3. The largest element in a sorted array is the last element.
4. The maximum number of pages a student will have to read is the sum of all array elements. (when N = 1)
5. Calculate Mid using the formula Low + (High-Low)/2.
6. Check if you can assign 'm' students to read a maximum of 'Mid' pages each.
7. If not, reduce the number of pages bu setting High=Mid-1
8. Else, set Low=Mid+1

Time Complexity : O(N*LogN)
Space Complexity : O(1)

https://www.youtube.com/watch?v=Ss9ta1zmiZo&ab_channel=CodingBlocks
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool isPossible(vector<int> V, int numStudents, int currMax)
{
    int studentsRequired = 1, currSum = 0;

    for (auto page : V)
    {
        if (page > currMax)
            return false;

        if ((currSum + page) > currMax)
        {
            studentsRequired++;
            currSum = page;
            if (studentsRequired > numStudents)
                return false;
        }
        else
            currSum += page;
    }
    return true;
}

int minNoOfPages(vector<int> V, int numStudents)
{
    // Return -1 if the number of books is less than the number of students
    if (V.size() < numStudents)
        return -1;

    int Sum = accumulate(V.begin(), V.end(), Sum);

    // The result will be in the range of the largest element in the array and the sum of the array.
    // The lower bound will be the largest array element because for each subarray combination, the maximum subarray sum has to be greater than the largest array element.
    int Low = V.back(), High = Sum;
    int Res;

    while (Low <= High)
    {
        // Mid here represents the maximum number of pages a student will read
        int Mid = Low + (High - Low) / 2;

        if (isPossible(V, numStudents, Mid))
        {
            // Mid is a candidate
            Res = Mid;
            High = Mid - 1;
        }
        else
            Low = Mid + 1;
    }
    return Res;
}

int main(void)
{
    // vector<int> V = {10, 20, 30, 40};
    // int numStudents = 4;

    vector<int> V = {2, 5, 7, 8, 10};
    int numStudents = 2;

    cout << minNoOfPages(V, numStudents);

    return 0;
}

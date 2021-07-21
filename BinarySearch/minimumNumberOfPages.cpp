// Given number of pages in n different books and m students.The books are arranged in ascending order of number of pages.Every student is assigned to read some consecutive books.The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

/*
Input : pages[] = {12, 34, 67, 90}
        m = 2
Output : 113
Explanation:
There are 2 number of students. Books can be distributed 
in following fashion : 
  1) [12] and [34, 67, 90]
      Max number of pages is allocated to student 
      2 with 34 + 67 + 90 = 191 pages
  2) [12, 34] and [67, 90]
      Max number of pages is allocated to student
      2 with 67 + 90 = 157 pages 
  3) [12, 34, 67] and [90]
      Max number of pages is allocated to student 
      1 with 12 + 34 + 67 = 113 pages

Of the 3 cases, Option 3 has the minimum pages = 113.

https://www.youtube.com/watch?v=Ss9ta1zmiZo&ab_channel=CodingBlocks
*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int Arr[], int n, int m, int curr_min)
{
    int studentsRequired = 1;
    int curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        // check if current number of pages are greater
        // than curr_min that means we will get the result
        // after mid no. of pages
        if (Arr[i] > curr_min)
        {
            return false;
        }
        if (curr_sum + arr[i] > curr_min)
        {
            studentsRequired++;
            curr_sum = arr[i];
            if (studentsRequired > m)
            {
                return false;
            }
        }
        else
        {
            curr_sum += arr[i];
        }
    }
}

int minNoOfPages(int Arr[], int n, int m)
{
    int Sum = 0;

    // Return -1 if the number of books is less than the number of students
    if (n < m)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        Sum += Arr[i];
    }

    int Low = 0, High = Sum;
    int Result = INT_MAX;

    while (Low <= High)
    {
        int Mid = Low + (High - Low) / 2;

        if (isPossible(Arr, n, m, Mid))
        {
            Result = Mid;
            High = Mid - 1;
        }
        else
        {
            Low = Mid + 1;
        }
    }
    return Result;
}

int main(void)
{
    int pageArr[] = {10, 20, 30, 40};
    int Size = sizeof(pageArr) / sizeof(pageArr[0]);
    int noOfStudents = 2;

    int minPages = minNoOfPages(pageArr, Size, noOfStudents);
    cout << minPages;
    return 0;
}

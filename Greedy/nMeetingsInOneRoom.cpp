/*
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. Print all meeting numbers

APPROACH:
Create a struct to store the starting time, ending time and order of each meeting.
Sort the structure in ascending order of the ending time
Push the first meeting which gets over to the result vector
Iterate from  1 to N-1 and check if the start time of any of the meetings is greater than the end time of the last concluded meeting.
Push that meeting to the vector and reset the last concluded meeting.

Time Complexity : O(N) + O(NlogN) + O(N) ~ O(NlogN)
Space Complexity : O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting
{
    int Start;
    int End;
    int Pos;
};

bool compare(struct Meeting m1, struct Meeting m2)
{
    return m1.End < m2.End;
}

void maximumMeetingsInOneRoom(vector<int> V1, vector<int> V2)
{
    int n = V1.size();
    struct Meeting meet[n];

    for (int i = 0; i < n; i++)
    {
        // Starting time of meeting i.
        meet[i].Start = V1[i];

        // Finishing time of meeting i
        meet[i].End = V2[i];

        // Original position/index of meeting
        meet[i].Pos = i + 1;
    }

    // Sorting of meeting according to their finish time.
    sort(meet, meet + n, compare);

    vector<int> M;

    // Initially insert first meeting.
    M.push_back(meet[0].Pos);

    int timeLimit = meet[0].End;

    // Insert all those meetings in the vector which can be conducted or not
    for (int i = 1; i < n; i++)
    {
        if (meet[i].Start > timeLimit)
        {
            M.push_back(meet[i].Pos);
            timeLimit = meet[i].End;
        }
    }

    // Print positions of selected meetings
    for (int i = 0; i < M.size(); i++)
        cout << M[i] << " ";
}

int main(void)
{
    vector<int> V1 = {1,
                      3,
                      0,
                      5,
                      8,
                      5};
    vector<int> V2 = {2,
                      4,
                      6,
                      7,
                      9,
                      9};
    maximumMeetingsInOneRoom(V1, V2);
    return 0;
}

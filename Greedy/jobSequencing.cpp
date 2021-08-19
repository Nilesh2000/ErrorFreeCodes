/*
Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes a single unit of time, so the minimum possible deadline for any job is 1. Maximize total profit only if one job can be scheduled at a time.

Approach :
Sort jobs in ascending order of profit.
Our approach here should be that we should perform a job only on the last day of their deadline because each job takes only 1 unit of time to perform.
Delaying a job till the last date of the deadline allows us to perform jobs which have deadlines smaller than the job to be performed earlier.

Time Complexity : O(NlogN) + (N*M) (Time for sorting + Time Required To Search For Appropriate Day To Perform Job)
Space Complexity : O(M), M is the maximum number of jobs you can perform
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    int Id;
    int Deadline;
    int Profit;
};

bool compare(struct Job j1, struct Job j2)
{
    return j1.Profit > j2.Profit;
}

void jobSequencing(struct Job jobs[], int n)
{
    // Sort jobs in descending order of profit
    sort(jobs, jobs + n, compare);

    int totalProfit = 0;
    int totalJobs = 0;

    // Find the maximum deadline

    // Deadline cannot be negative so we can set maxIndex to 0 instead of
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (jobs[i].Deadline > maxDeadline)
            maxDeadline = jobs[i].Deadline;
    }

    // Create a vector of size n and initialize all elements to -1
    // We initialize it with a size n we cannot perform more than n jobs
    vector<int> R(n, -1);

    for (int i = 0; i < n; i++)
    {
        // Perform the job on the last daty of the deadline
        // j here is an iterator to signify on what date we intend to perform the job
        for (int j = jobs[i].Deadline; j > 0; j--)
        {
            // Empty Slot Found
            if (R[j] == -1)
            {
                R[j] = jobs[i].Id;
                totalJobs++;
                totalProfit += jobs[i].Profit;
                break;
            }
        }
    }

    cout << "Total Number of Jobs : " << totalJobs;
    cout << "\nTotal Profit : " << totalProfit;
}

int main(void)
{
    struct Job jobs[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);
    return 0;
}

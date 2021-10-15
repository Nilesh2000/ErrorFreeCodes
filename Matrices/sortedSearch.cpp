/* 
Program to search an element in row-wise and column-wise sorted matrix

APPROACH:
1. Find the smallest and largest element
2. Start searching from the top right element.
3. If search > M[i][j], go downwards
4. If search < M[i][j], go left
5. Else element is found

Time Complexity : O(M + N)
Space Complexity : O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

bool sortedSearch(vector<vector<int>> M, int x)
{
	int numRows = M.size();
	int numCols = M[0].size();

	int smallest = M[0][0], largest = M[numRows - 1][numCols - 1];
	if (x < smallest || x > largest)
		return false;

	//Set indexes for top right element
	int i = 0, j = numCols - 1;
	while (i < numRows && j >= 0)
	{
		if (M[i][j] == x)
			return true;

		if (M[i][j] > x)
			j--;
		else // if M[i][j] < x
			i++;
	}
	return false;
}

int main(void)
{
	vector<vector<int>> M = {{10, 20, 30, 40},
							 {15, 25, 35, 45},
							 {27, 29, 37, 48},
							 {32, 33, 39, 50}};

	cout << sortedSearch(M, 29);
	cout << sortedSearch(M, 31);

	return 0;
}

// C++ program to search an element in row-wise and column-wise sorted matrix
#include <iostream>
using namespace std;

void sortedSearch(int Mat[4][4], int n, int x)
{
	int smallest = Mat[0][0], largest = Mat[n - 1][n - 1];
	if (x < smallest || x > largest)
	{
		cout << "\nElement is not present in the matrix.";
		return;
	}

	//Set indexes for top right element
	int i = 0, j = n - 1;
	while (i < n && j >= 0)
	{
		if (Mat[i][j] == x)
		{
			cout << "n Found at " << i << ", " << j;
			return;
		}
		if (Mat[i][j] > x)
			j--;
		else // if mat[i][j] < x
			i++;
	}
	cout << "Element not found";
}

int main(void)
{
	int Mat[4][4] = {{10, 20, 30, 40},
									 {15, 25, 35, 45},
									 {27, 29, 37, 48},
									 {32, 33, 39, 50}};
	// sortedSearch(Mat, 4, 31);
	sortedSearch(Mat, 4, 29);
	return 0;
}
//End of program

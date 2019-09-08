// A C++ program to merge k sorted arrays of Size n each.
# include <iostream>
# include <climits>
using namespace std;

# define n 4
// A min heap node
struct MinHeapNode
{
	int Element; // The Element to be stored
	int i; // index of the array from which the Element is taken
	int j; // index of the next Element to be picked from array
};

// Prototype of a utility function to swap two min heap nodes
void swap(MinHeapNode *x, MinHeapNode *y);

// A class for Min Heap
class MinHeap
{
	MinHeapNode *heapArray; // pointer to array of elements in heap
	int heapSize; // Size of min heap

  public:
	// Constructor: creates a min heap of given Size
	MinHeap(MinHeapNode Arr[], int Size);

	// to heapify a subtree with root at given index
	void MinHeapify(int);

	// to get index of left child of node at index i
	int leftChild(int i)
  {
    return (2*i + 1);
  }

	// to get index of right child of node at index i
	int rightChild(int i)
  {
    return (2*i + 2);
  }

	// to get the root
	MinHeapNode getMin()
  {
    return heapArray[0];
  }

	// to replace root with new node x and heapify() new root
	void replaceMin(MinHeapNode x)
  {
    heapArray[0] = x;
    MinHeapify(0);
  }
};

// This function takes an array of arrays as an argument and All arrays are assumed to be sorted. It merges them together and prints the final sorted outputArr.
int *mergeKArrays(int Arr[][n], int k)
{
	int *outputArr = new int[n*k]; // To store outputArr array
	//Create a min heap with k heap nodes. Every heap node has first Element of an array
	MinHeapNode *heapArray = new MinHeapNode[k];

	for (int i = 0; i < k; i++)
	{
		heapArray[i].Element = Arr[i][0]; // Store the first Element
		heapArray[i].i = i; // index of array
		heapArray[i].j = 1; // Index of next Element to be stored from array
	}

  MinHeap hpObj(heapArray, k); // Create the heap

	// Now one by one get the minimum Element from min heap and replace it with next Element of its array
	for (int Count = 0; Count < n * k; Count++)
	{
		// Get the minimum Element and store it in outputArr
		MinHeapNode root = hpObj.getMin();
		outputArr[Count] = root.Element;

		// Find the next elelement that will replace current root of heap. The next Element belongs to same array as the current root.
		if (root.j < n)
		{
			root.Element = Arr[root.i][root.j];
			root.j += 1;
		}
		// If root was the last Element of its array
		else
      root.Element = INT_MAX; //INT_MAX is for infinite

		// Replace root with next Element of array
		hpObj.replaceMin(root);
	}

	return outputArr;
}

// Constructor: Builds a heap from a given array Arr[] of given Size
MinHeap::MinHeap(MinHeapNode Arr[], int Size)
{
	heapSize = Size;
	heapArray = Arr; // store address of array
	int i = (heapSize - 1) / 2;
	while (i >= 0)
	{
		MinHeapify(i);
		i--;
	}
}

// A recursive method to heapify a subtree with root at given index. This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = leftChild(i);
	int r = rightChild(i);
	int Smallest = i;
	if(l < heapSize && heapArray[l].Element < heapArray[i].Element)
		Smallest = l;
	if(r < heapSize && heapArray[r].Element < heapArray[Smallest].Element)
		Smallest = r;
	if(Smallest != i)
	{
		swap(&heapArray[i], &heapArray[Smallest]);
		MinHeapify(Smallest);
	}
}

//A function to swap two elements
void swap(MinHeapNode *x, MinHeapNode *y)
{
	MinHeapNode Temp = *x;
  *x = *y;
  *y = Temp;
}

// Driver program to test above functions
int main(void)
{
	// Change n at the top to change number of elements in an array
	int Arr[][n] = {
                  {2, 6, 12, 34},
					        {1, 9, 20, 1000},
					        {23, 34, 90, 2000}
                 };
	int k = sizeof(Arr) / sizeof(Arr[0]);

	int *outputArr = mergeKArrays(Arr, k);
	cout << "Merged array is :-" << endl;
  for(int i = 0 ; i < n * k ; i++)
    cout << outputArr[i] << " ";

	return 0;
}

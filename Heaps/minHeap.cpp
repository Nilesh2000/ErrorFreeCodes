// A C++ program to demonstrate common MinHeap Operations
# include <iostream>
# include <climits> //Used for INT_MAX and INT_MIN
using namespace std;

//Function to swap two integers
void swap(int *x, int *y)
{
  int Temp = *x;
  *x = *y;
  *y = Temp;
}

// A class for Min Heap
struct MinHeap
{
	int *heapArray; // pointer to array of elements in heap
	int Capacity; // maximum possible size of min heap
	int heapSize; // Current number of elements in min heap

  //Constructor
	MinHeap(int maxCap)
  {
    heapSize = 0;
    Capacity = maxCap;
    heapArray = new int[maxCap];
  }

	//To heapify a subtree with the root at given index
	void MinHeapify(int);

	int Parent(int i)
  {
     return (i - 1)/2;
  }

	//to get index of left child of node at index i
	int leftChild(int i)
  {
    return ((2 * i) + 1);
  }

	//to get index of right child of node at index i
	int rightChild(int i)
  {
    return ((2 * i) + 2);
  }

	//To extract/Delete the root which is the minimum element
	int extractMin();

	//Decreases key value of key at index i to newVal
	void decreaseKey(int i, int newVal);

	//Returns the minimum key (key at root) from min heap
	int getMin()
  {
    return heapArray[0]; //Root is always stored as the first element of the array.
  }

	// Deletes a key stored at index i
	void deleteKey(int i);

	// Inserts a new key 'k'
	void insertKey(int k);
};

//Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
	if (heapSize == Capacity)
	{
		cout << "Overflow: Could not insert Key\n";
		return;
	}

	//First insert the new key at the end
	heapSize++;
	int i = heapSize - 1;
	heapArray[i] = k;

	// Fix the min heap property if it is violated
	while (i != 0 && heapArray[Parent(i)] > heapArray[i])
	{
    swap(&heapArray[i], &heapArray[Parent(i)]);
    i = Parent(i);
	}
  cout << k << " was inserted into the heap.\n";
}

// Decreases value of key at index 'i' to newVal. It is assumed that newVal is smaller than heapArray[i].
void MinHeap::decreaseKey(int i, int newVal)
{
	heapArray[i] = newVal;
	while (i != 0 && heapArray[Parent(i)] > heapArray[i])
	{
    swap(&heapArray[i], &heapArray[Parent(i)]);
    i = Parent(i);
	}
}

//Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
	if (heapSize <= 0)
		return INT_MAX;

	if (heapSize == 1)
	{
		heapSize--;
		return heapArray[0];
	}

	// Store the minimum value, and remove it from heap
	int Root = heapArray[0];
	heapArray[0] = heapArray[heapSize - 1]; //We now initialize the last element of the array as the root element.
	heapSize--; //Then, decrease the size of the heap. Now you know why we transferred the last element of the array to the root.
	MinHeapify(0); //heapify the element at index 0 which is the root.
	return Root;
}

// This function deletes key at index i. It first reduced value to minus infinity, then calls extractMin().
void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
  cout << i << " was deleted from the heap.\n";
}

/*
A recursive method to heapify a subtree with the root at given index. This method assumes that the subtrees are already heapified
The logic is as follows:-
We first assume that the root has the minElement element.
Then, we compare the left and right child of the root.
If any one of them is smaller than the root, then we make that element as the root and call MinHeapify() recursively.
Else, if the root is the smaller than the left and right child, we exit from the function.
*/
void MinHeap::MinHeapify(int i)
{
	int l = leftChild(i);
	int r = rightChild(i);
	int minElement = i;

	if (l < heapSize && heapArray[l] < heapArray[i])
		minElement = l;
	if (r < heapSize && heapArray[r] < heapArray[minElement])
		minElement = r;

	if (minElement != i)
	{
		swap(&heapArray[i], &heapArray[minElement]);
		MinHeapify(minElement);
	}

}

void Menu()
{
    int Choice = 0;
    MinHeap Obj(10);
    while(Choice != 6)
    {
        cout << "\nEnter Any One Of The Following Choices:-"
             << "\n1. Insert Key Into The Heap"
             << "\n2. Delete Key From The Heap"
             << "\n3. Extract Minimum From The Heap"
             << "\n4. Decrease Key Value"
             << "\n5. Get Minimum Value Of The Heap"
             << "\n6. Exit"
             << "\nYour choice is : ";
        cin >> Choice;
        int x, y;
        switch(Choice)
        {
            case 1 : cout << "\nEnter the key to be inserted : ";
                     cin >> x;
                     Obj.insertKey(x);
                      break;

            case 2 : cout << "\nEnter the key to be deleted : ";
                     cin >> x;
                     Obj.deleteKey(x);
                      break;

            case 3 : cout << '\n' << Obj.extractMin() << " has been deleted from the heap.\n";
                      break;

            case 4 : cout << "\nEnter the key to be decreased and the new value of the key : ";
                     cin >> x >> y;
                     Obj.decreaseKey(x, y);
                      break;

            case 5 : cout << "\nMinimum element in the heap is : " << Obj.getMin() << "\n";
                      break;

            case 6 : break;

            default : cout << "\nInvalid Choice.\n";
        }
    }
}

int main()
{
  Menu();
	return 0;
}

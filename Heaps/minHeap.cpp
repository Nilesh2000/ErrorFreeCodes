/*
Illustration of a min-heap.

Heaps come in two forms, namely min-heap and max-heap.
In a min-heap, all the elements are actually smaller than their children.
Thus, root node will be the smallest element in the heap.
Looking down the heap, the elements get bigger.

A heap is represented as a binary tree for easy understanding.
However, it is implemented as an array.

Array Implementation:
1. If the index of an element is i, then index of parent element (i-1)/2
2. Indices of the two children will be (2*i)+1 and (2*i)+2.

Insertion into a heap:-
1. Insert at the last empty position in the array.
2. However, it is not necessary that the element may be inserted at the right position.
3. Hence, after insertion, we bubble it up to its correct place.

Deletion the smallest element:-
1. The root node will be the smallest element
2. Thus, we first store value present in V[0].
3. Then, we set V[0] to V[Size-1].
4. This may not be the right position for V[0].
5. Hence, we bubble down the heap.

Time Complexities :-
ExtractMin() - O(1)
Insert() - O(log n)
Delete() - O(log n)
*/

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

class minHeap
{
private:
    int size;
    int capacity;
    int *heapArr;

    // Helper methods
    int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
    int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }
    int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }

    bool hasLeftChild(int index) { return getLeftChildIndex(index) < size; }
    bool hasRightChild(int index) { return getRightChildIndex(index) < size; }
    bool hasParent(int index) { return getParentIndex(index) >= 0; }

    int leftChild(int index) { return heapArr[getLeftChildIndex(index)]; }
    int rightChild(int index) { return heapArr[getRightChildIndex(index)]; }
    int parent(int index) { return heapArr[getParentIndex(index)]; }

    void swap(int indexOne, int indexTwo)
    {
        int t = heapArr[indexOne];
        heapArr[indexOne] = heapArr[indexTwo];
        heapArr[indexTwo] = t;
    }

    // If heap becomes full, resize the heap to store double the elements
    void ensureExtraCapacity()
    {
        if (size == capacity)
        {
            int newSize = size * 2;
            int *newArr = new int[newSize];
            memcpy(newArr, heapArr, size * sizeof(int));
            delete[] heapArr;
            heapArr = newArr;
            capacity *= 2;
        }
    }

public:
    // Initial Values
    minHeap()
    {
        size = 0;
        capacity = 5;
        heapArr = new int[capacity];
    }

    // Extract the smallest element
    int peek()
    {
        if (size == 0)
            return INT_MIN;
        return heapArr[0];
    }

    // Extract and delete the smallest element
    int poll()
    {
        if (size == 0)
            return INT_MIN;

        int num = heapArr[0];
        heapArr[0] = heapArr[size - 1];
        size--;
        heapifyDown();
        return num;
    }

    // Insert into heap
    void add(int num)
    {
        ensureExtraCapacity();
        heapArr[size] = num;
        size++;
        heapifyUp();
    }

    void heapifyUp()
    {
        int index = size - 1; // Get index of last inserted element
        // Bubble the element upwards
        while (hasParent(index) && parent(index) > heapArr[index])
        {
            swap(getParentIndex(index), index);
            index = getParentIndex(index);
        }
    }

    void heapifyDown()
    {
        // The index of the element to be bubbled down is 0
        int index = 0;
        // We check only for left child because if the node does not have left child, it defintely won't have right child
        while (hasLeftChild(index))
        {
            // Get the smaller of the left and right children incase the right child exists
            int smallerChildIndex = getLeftChildIndex(index);
            if (hasRightChild(index) && rightChild(index) < leftChild(index))
                smallerChildIndex = getRightChildIndex(index);

            // If the heap condition is satisfied, exit
            if (heapArr[index] < heapArr[smallerChildIndex])
                break;
            // Else, bubble down the heap
            else
                swap(index, smallerChildIndex);

            index = smallerChildIndex;
        }
    }
};

int main(void)
{
    minHeap Obj;

    Obj.add(10);
    Obj.add(15);
    Obj.add(20);
    cout << Obj.peek() << '\n';

    Obj.add(12);
    Obj.add(19);
    Obj.add(8);

    cout << Obj.poll() << "\n";
    cout << Obj.peek();

    return 0;
}

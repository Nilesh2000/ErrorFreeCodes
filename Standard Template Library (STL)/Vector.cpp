/*
Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being
handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using
iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes there may be a need of extending
the array. Removing the last element takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle
is linear in time.
*/

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;
int main()
{
    vector <int> v1, v2, v3 {1, 2, 3, 4, 5}; //Declaration of a vector
    vector <int> ::iterator it1; //Declaration of an iterator to access a vector
    vector <int> ::reverse_iterator it2; //A reverse iterator is used to access elements of a vector in the reverse dierection.
    vector <int> ::const_iterator it3; //A constant iterator is used to access vector elements without modifying them.
    vector <int> ::const_reverse_iterator it4; //A constant reverse iterator is used to access vector elements in the reverse dierection without
                                               //modifying them.

      for(int i = 1 ; i <=6 ; i++)
        v1.push_back(i); //Pushing elements the end of a vector
      for(int j = 6 ; j >= 1 ; j--)
        v2.push_back(j);

    //begin()-Returns an iterator pointing to the first element in the vector
    //end()- Returns an iterator pointing to the theoretical element that follows the last element in the vector

      for(it1 = v1.begin() ; it1 != v1.end() ; it1++)
        cout << *it1 << " "; //Displaying vector elements in forward dierection
        //*it refers to dereferencing a iterator to display the value at that address.
    cout << endl;
      for(it2 = v1.rbegin() ; it2 != v1.rend() ; it2++)
        cout << *it2 << " "; //Displaying vector elements in reverse dierection using a reverse vector.
    cout << endl;
      for(it3 = v1.cbegin() ; it3 != v1.cend() ; it3++)
        cout << *it3 << " ";
    cout << endl;
      for(it4 = v1.crbegin() ; it4 != v1.crend() ; it4++)
        cout << *it4 << " ";
    cout << "\n\n";
    cout << "Size of vector (number of elements) : "<< v1.size(); //Size returns number of elements in the vector.
    cout << endl;
    cout << "Maximum Capacity : " << v1.max_size(); //Returns the maximum number of elements that the vector can hold.
    cout << endl;
    cout << "Capacity : " << v1.capacity();//Returns the size of the storage space currently allocated to the vector expressed as number of elements.
    cout << endl;
    int n = 5;
    v1.resize(n); //Resizes the container so that it contains 'n' elements.
    cout << "After Resizing : ";
    for(it1 = v1.begin() ; it1 != v1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;
    cout << "Empty or not : " << v1.empty();//Returns whether the container is empty (0 denotes not empty)
    cout << endl;
    v1.shrink_to_fit();//Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
    v1.reserve(n);//Requests that the vector capacity be at least enough to contain n elements.

    int a = 2;
    cout << a << " element of the vector : "<< v1.at(a); //Displays the ath element of the vector;
    cout << endl;

    cout << "First element of the vector : " << v1.front();
    cout << endl;
    cout << "Last element of the vector : " << v1.back();
    cout << endl;
    //data() - Returns a direct pointer to the memory array used internally by the vector to store its own elements.
    int *Pos = v1.data();
    cout << "First element : " << *Pos << " Second element : " << *(Pos + 1);
    cout << endl;

    int n1 = 5, n2 = 10; //Fills the vector with element n2 n1 times.
    v1.assign(n1, n2);
    cout << "\nAfter Assigning : ";
    for(it1 = v1.begin() ; it1 != v1.end() ; it1++)
      cout << *it1 << " ";

    v1.pop_back(); //Use to pop elements from the vector from the back.
    cout << "\nAfter performing a pop back : ";
    for(it1 = v1.begin() ; it1 != v1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    int p = 1;
    v1.insert(v1.begin(), p); //Used to insert the pth element at the specified position / address.
    cout << "After insertion at specified position : ";
    for(it1 = v1.begin() ; it1 != v1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    auto it = v1.begin(); //Auto keyword will automatically typecast the datatype for the required expression.
    advance(it, 2); //Moving the iterator forward by 2 steps.
    v1.erase(it); //Removes the element at the specified position
    cout << "After deletion at specified position : ";
    for(it1 = v1.begin() ; it1 != v1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    //v1.clear(); //Used to remove all elements of the vector.

    v1.swap(v2);
    cout << "After Swapping :-\n";
    cout << "Vector 1 : ";
    for(it1 = v1.begin() ; it1 != v1.end() ; it1++)
      cout << *it1 << " ";
    cout << "\nVector 2 : ";
    for(it1 = v2.begin() ; it1 != v2.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    cout << "Vector in ascending order : ";
    sort(v1.begin(), v1.end()); //Sort a vector in ascending order
    for(it1 = v1.begin() ; it1 != v1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    cout << "Vector in descending order : ";
    sort(v1.begin(), v1.end(), greater<int>()); //Sort a vector in descending order
    for(it1 = v1.begin() ; it1 != v1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

/*
The range used is [first,last), which contains all the elements between first and last, including the element pointed by first but not the element
pointed by last.
Syntax:
void reverse(BidirectionalIterator first, BidirectionalIterator last)
BidirectionalIterator is an iterator that can be used to access any
elements of a container in both forward and backward direction.
*/
    cout << "Reverse Of A Vector : ";
    reverse(v1.begin() + 2, v1.end() - 1);
    for(auto it : v1) //A novel method to display the elements of a vector.
      cout << it << " ";
    cout << "\n\t\t      ";

    for(auto &it : v1) //Incase we use a reference to an iterator, changes to the vector elements wil be reflected.
      {
       it++;
       cout << it << " ";
     }
    return 0;
}

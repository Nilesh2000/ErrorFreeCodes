/*
Lists are sequence containers that allow non-contiguous memory allocation. As compared to vector, list has slow traversal, but once a position has
been found, insertion and deletion are quick. Normally, when we say a List, we talk about doubly linked list. For implementing a singly linked list,
we use forward_list.
*/

# include <iostream>
# include <list>
# include <algorithm>

using namespace std;

bool odd(const int &num)
{
    return (num % 2);
}


int main(void)
{
    list <int> l1, l2; //Declaration of a list
    list <int> ::iterator it1; //Declaration of an iterator to access the elements of the list
    list <int> ::reverse_iterator it2; //A reverse iterator is used to access elements of a list in the reverse dierection.
    list <int> ::const_iterator it3; //A constant iterator is used to access list elements without modifying them.
    list <int> ::const_reverse_iterator it4; //A constant reverse iterator is used to access list elements in the reverse dierection without
                                               //modifying them.

    for(int i = 1 ; i <= 4 ; i++)
      {
        l1.push_back(i); //Pushing elements to the end of a list
        l1.push_front(i * 2); //Pushing elements to the front of a list
      }

    //begin()-Returns an iterator pointing to the first element in the list
    //end()- Returns an iterator pointing to the theoretical element that follows the last element in the list
    for(it1 = l1.begin() ; it1 != l1.end() ; it1++)
      cout << *it1 << " "; //Displaying list elements in forward dierection
    cout << endl;
    for(it2 = l1.rbegin() ; it2 != l1.rend() ; it2++)
      cout << *it2 << " "; //Displaying list elements in reverse dierection using a reverse vector.
  cout << endl;
    for(it3 = l1.cbegin() ; it3 != l1.cend() ; it3++)
      cout << *it3 << " ";
  cout << endl;
    for(it4 = l1.crbegin() ; it4 != l1.crend() ; it4++)
      cout << *it4 << " ";
  cout << "\n\n";

    cout << "First element of the list : " << l1.front(); //Returns the value of the first element in the list
    cout << endl;
    cout << "Last element of the list : " << l1.back(); //Returns the value of the last element in the list
    cout << endl;

    l1.pop_back(); //Removes the last element
    l1.pop_front(); //Removes the first element
    cout << "After Popping list elements : ";
    for(it1 = l1.begin() ; it1 != l1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    l1.reverse(); //Reversing a list
    cout << "After Reversing List : ";
    for(it1 = l1.begin() ; it1 != l1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    l1.sort(); //Sorting a list
    cout << "After Sorting List : ";
    for(it1 = l1.begin() ; it1 != l1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    cout << "Size of the list is : "<< l1.size(); //Returns the number of elements in the list.
    cout << endl;

    cout << "Maximum elements the list can hold : " << l1.max_size();;
    cout << endl;

    cout << "Empty or not : " << l1.empty(); //Returns whether the list is empty(1) or not(0).
    cout << "\n\n";

    int p = 10;
    l1.insert(l1.begin(), p); //Used to insert the pth element at the specified position / address.
    cout << "After insertion at specified position : ";
    for(it1 = l1.begin() ; it1 != l1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    cout << "List after resizing it to 5 elements : ";
    l1.resize(5); //Used to resize a list container.
    for(it1 = l1.begin() ; it1 != l1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    cout << "List after resizing it to 6 elements : ";
    l1.resize(6); //Used to resize a list container.
    for(it1 = l1.begin() ; it1 != l1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    cout << "List after resizing it to 8 elements and also assigning a value : ";
    l1.resize(8, 9); //Used to resize a list container.
    for(it1 = l1.begin() ; it1 != l1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;
/*
This function can be used to remove a single element or a range of elements from the specified list container.

Syntax:
iterator list_name.erase(iterator position)
or,
iterator list_name.erase(iterator first, iterator last)

This function returns an iterator pointing to the element in the list container which followed the last element erased from the list container.
*/

    it1 = l1.begin();
    advance(it1, 2); //Moving the iterator forward by 2 steps.
    l1.erase(it1);
    cout << "\nList after deleting a single element : ";
    for(it1 = l1.begin() ; it1 != l1.end() ; it1++)
      cout << *it1 << " ";

    it1 = l1.begin();
    auto it = l1.begin();
    advance(it, 3); //Moving the iterator forward by 3 steps.
    l1.erase(it1, it);
    cout << "\nList after deleting a group of elements : ";
    for(it1 = l1.begin() ; it1 != l1.end() ; it1++)
      cout << *it1 << " ";

    l1.assign(4, 3); //Assigns new elements to list by replacing current elements and resizes the list.
                     //Assigns the number 3 4 times.
    cout << "\nList 1 after assigning elements : ";
    for(it1 = l1.begin() ; it1 != l1.end() ; it1++)
      cout << *it1 << " ";

/*
To copy elements from an existing list to a new list.

Syntax:
first_list.assign(second_list.begin(), second_list.end());
Parameters: This function accepts two parameter as shown in the above syntax. The first parameter is the beginning iterator of the second list
and second parameter is the ending iterator of the second list.
Return Value: This function copies the second_list to first_list. This function does not returns any value.
*/
    cout << "\nList 2 after copying value from list 1 : ";
    l2.assign(l1.begin(), l1.end());
    for(it1 = l2.begin() ; it1 != l2.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    for(int i = 1 ; i <= 8 ; i++)
      l1.push_back(i);

    l1.remove(3); //Removes all the elements from the list, which are equal to given element.
    cout << "List after removing all instances of 3 : ";
    for(it1 = l1.begin() ; it1 != l1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

/*
remove_if() function is used to remove all the values from the list that correspond true to the predicate or condition given as parameter to the
function. The function iterates through every member of the list container and removes all the element that return true for the predicate.
*/

    cout << "List after removing elements which are odd : ";
    l1.remove_if(odd); //Definition for odd on line 13.
    for(auto Iter : l1) //A novel method to display the elements of a vector.
      cout << Iter << " ";
    cout << "\n\n";

    //Creating two new lists
    l1.erase(l1.begin(), l1.end());
    l2.erase(l2.begin(), l2.end());


    list <int> l {1, 2, 3};
    for(int j = 12 ; j >= 10 ; j--)
      l2.push_front(j);

    l.swap(l2); //This function is used to swap the contents of one list with another list of same type and size.
    cout << "After Swapping:-\n";
    cout << "list 1 : ";
    for(auto Iter : l)
      cout << Iter << " ";
    cout << endl;

    cout << "list 2 : ";
    for(auto Iter : l2)
      cout << Iter << " ";
    cout << endl;

    l2.merge(l); //Merges two lists. l2 is appended to the end of l1.
    cout << "After merging two lists : ";
    for(auto Iter : l2)
      cout << Iter << " ";
    cout << endl;

/*
The list::splice() is a built-in function in C++ STL which is used to transfer elements from one list to another. The splice() function can be used
in three ways:

Transfer all the elements of list x into another list at some position.
Transfer only the element pointed by i from list x into the list at some position.
Transfers the range [first, last) from list x into another list at some position.
*/

    list <int> li1 = {1, 2, 3};
    list <int> li2 = {4, 5};
    list <int> li3 = {6, 7, 8};

/*
Parameters: The function accepts four parameters which are specified as below:

position – Specifies the position where the elements are to be transfered.
list2 – It specifies a list object of the same type which is to be transfered.
i – It specifies an iterator to the position of an element in list2 which is to be transfered.
first, last – Iterators specifying a range of elements in list2 which is to be transferred in list1. The range includes all the elements between
first and last, including the element pointed by first but not the one pointed by last.
Return value: This function does not returns anything.
*/

    // transfer all the elements of l2 to l1
    li1.splice(li1.begin(), li2);

    cout << "list 1 after splice operation : ";
    for(auto x : li1)
        cout << x << " ";

    // transfer all the elements of l1 to l3
    li3.splice(li3.begin(), li1);

    cout << "\nlist 3 after splice operation : ";
    for(auto x : li3)
        cout << x << " ";
    cout << endl;

    for(int i = 1 ; i <= 3 ; i++)
      li1.push_back(i);
    for(int i = 4 ; i <= 5 ; i++)
      li2.push_back(i);
    //iterator pointing to 4.
    it = li2.begin();
    //transfer 4 at the end of l1
    li1.splice(li1.end(), li2, it);
    cout << "list 1 after splice operation : ";
    for(auto x : li1)
        cout << x << " ";
    cout << endl;

    it = li1.begin();
    // advance the iterator by 2 positions
    advance(it, 2);
    li2.splice(li2.begin(), li2, it, li1.end());
    cout << "list 2 after splice operation : ";
    for(auto x : li2)
        cout << x << " ";
    cout << endl;

    cout << "List after clearing : ";
    l.clear(); //Used to clear the list. Makes the size 0.
    for(auto Iter : l)
      cout << Iter << " ";
    cout << endl;
}

/*
Sets are a type of associative containers in which each element has to be unique, because the value of the element identifies it. The value of the
element cannot be modified once it is added to the set, though it is possible to remove and add the modified value of that element.
*/

# include <iostream>
# include <set>

using namespace std;
int main()
{
    set <int> s1; //elements are inserted by default in ascending order.
    set <int> ::iterator it1;
    // insert (g) - Adds a new element ‘g’ to the set.
    s1.insert(20);
    s1.insert(50);
    s1.insert(40);
    s1.insert(30);
    s1.insert(10);
    s1.insert(20);
    s1.insert(50); //Only one 50 will be inserted. no duplicates are present in a set.
    for(it1 = s1.begin() ; it1 != s1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    set <int, greater<int> > s2 (s1.begin(), s1.end()); //elements copied from s1 to s2 are by default inserted in descending order.
    set <int, greater<int> > ::iterator it2;
    for(it2 = s2.begin() ; it2 != s2.end() ; it2++)
      cout << *it2 << " ";
    cout << endl;

    cout << "\nNumber of elements in set 1 : " << s1.size(); //Returns the number of elements in the set.
    cout << endl;
    cout << "Maximum elements the set can hold : " << s1.max_size(); // Returns the maximum number of elements that the set can hold.
    cout << endl;
    cout << "Is the set empty or not : " << s1.empty();
    cout << endl;

    cout << "\nSet after removing 40 : ";
    s1.erase(40);
    for(it1 = s1.begin() ; it1 != s1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    cout << "Set after removing the last element : ";
    auto it = s1.end(); //A easy method to declare an iterator
    advance(it, -1);
    s1.erase(it); // Removes the element at the position pointed by the iterator.
    for(it1 = s1.begin() ; it1 != s1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    cout << "Set after erasing elements upto 30 : ";
    s1.erase(s1.begin(), s1.find(30)); //erases all elements uptill where 30 is found.
    for(it1 = s1.begin() ; it1 != s1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    cout << "Set after clearing : ";
    s1.clear();
    for(it1 = s1.begin() ; it1 != s1.end() ; it1++)
      cout << *it1 << " ";
    cout << endl;

    return 0;
}

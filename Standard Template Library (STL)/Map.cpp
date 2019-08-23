/*
Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values can
have same key values.
*/
# include <iostream>
# include <iterator>
# include <map>

using namespace std;

int main()
{
    map <int, int> m1; //Declaration of a map variable
    map <int, int> ::iterator it1; //Declaration of an iterator to access the elements of the map.

    //iterator map_name.insert({key, element})
    //No two pairs can have the same key. Elements are automatically inserted in a ascending sorted fashio.
    m1.insert(pair<int, int>(1, 2)); //Insertion can take place only through pairs.
    m1.insert(pair<int, int>(3, 4));
    m1.insert(pair<int, int>(5, 6));
    m1.insert(pair<int, int>(7, 8));
    m1.insert({9, 10}); //Elements can also be inserted in this fashion.
    m1.insert(pair<int, int>(1, 5)); //If a same key is attempted to insert twice, the program just ignores it.

    cout << "Map 1 after insertion : \n";
    for(it1 = m1.begin() ; it1 != m1.end() ; it1++)
    {
        cout << it1 -> first << " " << it1 -> second << endl;
    }
    cout << "Number of elements in map 1 and max size is: " << m1.size() << " " << m1.max_size();

    map <int, int> m2(m1.begin(), m1.end());
    m2.insert({11, 12});
    m2.insert({13, 14});

    //Removing all elements whose key is less than 5.
    m2.erase(m2.begin(),m2.find(5));

    cout << "\n\nMap 2 after removing all elements whose key is less than 5 :-\n";
    for(it1 = m2.begin() ; it1 != m2.end() ; it1++)
    {
        cout << it1 -> first << " " << it1 -> second << endl;
    }

    m2.erase(7); //Removing an element whose key is 7.
    auto it2 = m2.find(9);
    auto it3 = m2.find(13);
    m2.erase(it2, it3); //This will erase keys starting from 9 till 13 but not the pair which contians 13.
    m2.erase(it3);

    cout << "\nMap 2 after removing key 7, erasing within a given range and erasing pair with key 13 :\n";
    for(it1 = m2.begin() ; it1 != m2.end() ; it1++)
    {
        cout << it1 -> first << " " << it1 -> second << endl;
    }
}
//End of program

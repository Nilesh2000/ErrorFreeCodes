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
    //No two pairs can have the same key.
    m1.insert(pair<int, int>(1, 2)); //Insertion can take place only through pairs.
    m1.insert(pair<int, int>());

    for(it1 = m1.begin() ; it1 != m1.end() ; it1++)
    {
        cout << it1 -> first << " " << it1 -> second << endl;
    }
}

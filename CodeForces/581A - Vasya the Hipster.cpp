//Header Files
# include <iostream>

using namespace std;

int main(void) //Driver Function
{
    int redSocks, blackSocks;
    cin >> redSocks >> blackSocks;
    cout <<min(redSocks, blackSocks) <<" " <<( max(redSocks, blackSocks) - min(redSocks, blackSocks) ) / 2 <<endl;
    //Dividing by 2 because we have to calculate the number of pairs of the socks.
    return 0;
}
//End Of Program

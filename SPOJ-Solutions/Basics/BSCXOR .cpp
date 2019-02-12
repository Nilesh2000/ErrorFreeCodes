//Header Files
# include <iostream>

using namespace std;

int myXOR(int x, int y)
{
   return (x | y) & (~x | ~y); //Returning Result Of XOR Gate Back To Main Function
}
int main() //Main Function
{
   int x, y;
   cin >>x >>y; //Input Is Either 0 Or 1
   cout << myXOR(x, y); //Displaying Output
   return 0;
}

/*
Truth Table Of XOR Gate
A	B	Y
0	0	0
0	1	1
1	0	1
1	1	0
*/

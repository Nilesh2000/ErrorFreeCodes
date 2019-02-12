//Header Files
# include <iostream>

using namespace std;

int main(void) //Driver Function
{
    int r, c;
    cin >> r >> c;
      for(int i = 1 ; i <= r ; i++)
        {
            if(i % 4 == 0)
              {
                  cout << "#";
                    for(int j = 1 ; j < c ; j++)
                      {
                          cout << ".";
                      }
                  cout << endl;
              }
            else if(i % 4 == 2) //Necessary to use else if instead of if
              {
                    for(int j = 1 ; j < c ; j++)
                      {
                          cout << ".";
                      }
                  cout << "#" << endl;
              }
            else
              {
                    for(int j = 1 ; j <= c ; j++)
                      {
                          cout << "#";
                      }
                  cout << endl;
              }
        }
    return 0;
}
//End Of Program

/*Do some observation about the result, you can find this pattern:
(4k+1) / (4k+3) line: "#######"
(4k+2) line: ".......#"
(4k+0) line: "#......."

https://codeforces.com/blog/entry/16173
*/

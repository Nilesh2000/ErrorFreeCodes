//Header Files
# include <iostream>
# include <cstring>

using namespace std;

int main(void) //Driver Function
{
    int n, Faces = 0;
    string s;
    cin >> n;
      while(n--)
        {
            cin >> s;
              if(s.compare("Tetrahedron") == 0)
                {
                    Faces += 4;
                }
              if(s.compare("Cube") == 0)
                {
                    Faces += 6;
                }
              if(s.compare("Octahedron") == 0)
                {
                      Faces += 8;
                }
              if(s.compare("Dodecahedron") == 0)
                {
                        Faces += 12;
                }
               if(s.compare("Icosahedron") == 0)
                {
                          Faces += 20;
                }
        }
    cout << Faces << endl;
    return 0;
}
//End Of Program

//Header Files
# include <iostream>
# include <cstring>

using namespace std;

int main(void) //Driver Function
{
    int n;
    cin >> n;
    char s[10];
      while(n--)
        {
            cin >> s;
            int Res, Len = strlen(s); //Length of s
            int i = 1; //Starting with 1 because the 0th indexed character is guaranteed to be an alphabet

              while(i < Len && isdigit(s[i])) //
                {
                    i++;
                }

              //Case when string is RNum1CNum2 format
              if(i > 1 && i < Len)
                {
                  Res = 0;
                    for(int Iter = i + 1 ; Iter < Len ; Iter++) //Starting with i+1 because ith character isguaranteed to
                                                                //be an alphabet
                      {
                          Res = Res * 10 + (s[Iter] - '0'); //Converting the column number present in the string to an int
                      }
                  int Pow = 26; //Set Pow to Number of alphabets in english language.
                    while(Res > Pow)
                      {
                          Res -= Pow; //Decrement Res By Pow So that the corresponding column number can be computed.
                          Pow *= 26; //Multipying by 26 again because number of charcters in the column increase by 1 only
                               //every pow ((26, n) + 26 + 1) times.
                      }
                  Res--; //Decremnting Res becaue of 0-indexing (A = 0, B = 1, ... Z = 25)
                    while(Pow != 1)
                      {
                        Pow /= 26; //Dividing Pow By 26 so that the present column alphabet can be calculated.
                        cout << char(Res / Pow + 'A'); //Printing the character equivalent of the expression in the braces
                        Res %= Pow; //Finding remainder of Res and Pow so that next alphabet can be computed.
                      }
                  s[i] = '\0';
                  cout << s + 1 << endl; //Intially s points to beginning of the charecter array. After it has been null
                                    //terminated at i and it is pointed to second character of the array (s[1]), then it
                                    //prints out the string from s[1] to s[i-1].
                }

              //Case When Column in alphachars followed by row number

              else
                {
                    int Res = 0, Val = 0, Pow = 1;
                    int i = 0;
                      while(isalpha(s[i])) //Check if the character is an alphabet
                        {
                            Res += Pow; //Res determines the index of each of the alphabets present in the string
                            Pow *= 26; //Multiplying by 26 because number of charcters in the column increase by 1 only
                                       //every pow ((26, n) + 26 + 1) times.
                            Val = Val * 26 + s[i] - 'A'; //Val is used convert column alphabet into column int
                            i++; //Go on to the next character
                        }
                    Res += Val; //Incrementing Res By Val Because Val determines the number of characters in the Column
                    cout << "R" << s + i << "C" << Res << endl; //s is used as a pointer and it is pointing to s+i to
                                                                //begin with
                }
        }
    return 0;
}
//End Of Program

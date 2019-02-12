# include <iostream>
# include <string>
using namespace std;
int main()
{
    int Size, k;
    string s;
    cin >>Size >>s >>k;
    k%=26;
     for(int i=0;i<Size;i++)
     {
         int c=s[i];
          if(islower(c))
           {
            c+=k;
             if(c>'z')
                 c=96+(c%122);
           }
          else if(isupper(c))
           {
            c+=k;
             if(c>'Z')
                 c=64+(c%90);
           
           }
         cout <<(char)c;
     }
    return 0;
}

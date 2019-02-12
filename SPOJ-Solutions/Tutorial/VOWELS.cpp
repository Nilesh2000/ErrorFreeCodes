//Header Files
# include <iostream>
# include <string>

using namespace std;

int main() //Main Function
{
    string s;
    cin >>s; //Input The String Which Contains The Number Of Vowels To Be Counted
    int Len=s.length(), Vowel=0;
     for(int i=0;i<Len;i++)
      {
         //If Condition To Check Wheteher The Entered String Contains Vowels
             if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'
                || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                Vowel++;
       }
      cout <<Vowel; //Display Number Of Vowels Present in The String
      return 0;
}

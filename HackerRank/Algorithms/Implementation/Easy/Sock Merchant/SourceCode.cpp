# include <iostream>
using namespace std;
int main() 
{
    int n, Num;
    cin>>n;
    int Freq[101]={};
    for(int i=0;i<n;i++) 
    {
        cin>> Num;
        Freq[Num]++;
    }
    int Result=0;
    for(int i=0;i<=100;i++)
      Result+=Freq[i]/2;
    cout <<Result <<endl;
    return 0;
}

# include <iostream>
using namespace std;
int main()
{
    int n, Alice;
    cin >>n;
    int Arr[n], Rank[n];
    for(int i=0;i<n;i++)
        cin >>Arr[i];
    cin >>Alice;
    int Score[Alice];
     for(int i=0;i<Alice;i++)
         cin >>Score[i];
    int j=1;
    Rank[0]=1;
     while(j<=n)
     {
      Rank[j]=Rank[j-1];
         if(Arr[j-1]!=Arr[j])  
             Rank[j]++;
        j++; 
     }
    int k=n-1, Total=0;
     for(int i=0;i<Alice;i++)
     {
         Total=Score[i];
         int Alice_Rank=1;
          if(k>=0)
          {
              while((k>=0) && (Total>Arr[k]))
               k--;
              if(k<0)
               Alice_Rank=1; 
              else if(Total==Arr[k])
                Alice_Rank=Rank[k];
              else
                Alice_Rank=Rank[k]+1;   
          }
         cout <<Alice_Rank <<endl;
     }
    return 0;
}

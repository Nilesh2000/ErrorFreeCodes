//Header Files
# include <bits/stdc++.h>

using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b)
{
  return a.first - a.second > b.first - b.second;
}

int main(void) //Driver Function
{
  int numOfSongs, storageSize;
  cin >> numOfSongs >> storageSize;
  vector < pair <int, int> > a(numOfSongs);
  long long Sum = 0;
    for(int i = 0 ; i < numOfSongs ; i++)
      {
          cin >> a[i].first >> a[i].second;
          Sum += a[i].first;
      }
  //Sort the pair of the actual size of the song, and the compressed size of the song in a non -increasing order of The
  //difference of the actual size and the compressed size.
  sort(a.begin(), a.end(), cmp);
    for(int i = 0 ; i < numOfSongs ; i++)
      {
          if(Sum <= storageSize) //Check if the sum of the actual size of all the songs is lesser than the the maximum storage of The
                        //flash drive.
            {
                cout << i << endl;
                return 0;
            }
        Sum -= a[i].first - a[i].second;
      }
    if(Sum <= storageSize) //This condition will be true only if the control reaches outside the loop.
      {
          cout << numOfSongs << endl;
      }
    else
      {
          cout << -1 << endl;
      }
  return 0;
}
//End Of Program
//Refer the code at https://codeforces.com/blog/entry/60949

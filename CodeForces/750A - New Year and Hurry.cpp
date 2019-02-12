//Header Files
# include <iostream>

using namespace std;

int main(void) //Driver Function
{
    int n, k, reqTime = 0, Count = 0, timeToNewYear = 240;
    cin >> n >> k;
      for(int i = 1 ; i <= n ; i++)
        {
            reqTime = (5 * i); //5 minutes is required to solve the ith problem
            timeToNewYear -= reqTime; //Decremnt timeToNewYear by 5*i for every problem solved
              if(timeToNewYear < k) //Check if there is still enough time for him to travel
                {
                  break;
                }
            Count++; //Increment Count if control reaches outside the if construct
        }
    cout << Count << endl;
    return 0;
}
//End Of Program

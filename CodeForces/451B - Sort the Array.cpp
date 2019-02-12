//Header Files
# include <iostream>
# include <algorithm>

using namespace std;

int main(void) //Driver Function
{
    int n, Front = 0, End;
    cin >> n;
    int Arr[n];
      for(int i = 0 ; i < n ; i++)
        {
            cin >> Arr[i];
        }
    bool Flag = true;

    //Loop checks only till n-1 since the following if statement consists of an i+1 term

      for(int i = 0 ; i < n - 1 ; i++) //Loop to check if the array is already sorted
        {
            if(Arr[i] > Arr[i + 1]) //Condition to check if the succeeding element is largest than the present element
              {
                  Flag = false; //Set flag as false as soon as even one element is found which is not sorted
                  Front = i; //Set front = i , where ith term is not sorted
                   break;
              }
        }
      if(Flag) //If array is sorted, then just output yes along with the starting and ending indices as 1 each.
        {
            cout << "yes" << endl <<"1 1" <<endl;
            return 0; //Terminate from the program
        }
    End = Front; //Start with assigning end to front

    //First condition goes only till n-1 since end is incremented inside the loop
    //Second condition checks if the array is in reverse sorted order and thus we use the greater than operator (>).

      while(( End < n - 1 ) && ( Arr[End] > Arr[End + 1] ))
        {
            End++; //Increment end only when the above two conditions are true.
        }

    //The range used is [first,last), which contains all the elements between first and last, including the
    //element pointed by first but not the element pointed by last.

    reverse(Arr + Front, Arr + End + 1);  //From the above definition we infer why we add 1 in the second parameter.
      if(is_sorted(Arr, Arr + n))
        {
            cout << "yes" << endl << ++Front << " " << ++End << endl; //Incremnt front and end because they were initialized
                                                              //in a zero-index error.
        }
      else
        {
            cout << "no" << endl;
        }
    return 0;
}
//End Of Program
//https://github.com/gopiariv/codeforces/blob/master/451B.cpp

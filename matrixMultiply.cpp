# include <iostream>

using namespace std;

void MULTI(int A[3][3])
{
    int Res[3][3], Sum = 0;
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            for(int k = 0 ; k < 3 ; k++)
            {
                Sum += (A[i][k] * A[k][j]);
            }
            Res[i][j] = Sum;
            Sum = 0;
        }
    }
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            A[i][j] = Res[i][j];
        }
    }
}

int main(void)
{
    int Arr[3][3] = {{1,2,3},
                     {4,5,6},
                     {7,8,9}};
    MULTI(Arr);
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            cout << Arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

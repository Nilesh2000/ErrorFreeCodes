# include <iostream>

using namespace std;

void printMatrix(int Arr[][3])
{
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            cout << Arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void rotateClockwise(int Arr[][3])
{
    int Transpose[3][3];
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            Transpose[i][j] = Arr[j][i];
        }
    }

    int n = 3;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0, k = n - 1 ; j < n / 2 ; j++, k--)
        {
            int Temp = Transpose[i][j];
            Transpose[i][j] = Transpose[i][k];
            Transpose[i][k] = Temp;
        }
    }
    printMatrix(Transpose);
}

int main(void)
{
    int Mat[3][3] = {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
                    };
    printMatrix(Mat);
    rotateClockwise(Mat);
    return 0;
}

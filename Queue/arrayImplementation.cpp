//A program to implement the array implementation of a queue.
# include <iostream>
# define SIZE 5

using namespace std;

int Front = 0, Rear = 0;
int Queue[SIZE];

void Q_Insert(int Data)
{
    if(Rear == SIZE)
    {
        cout << "Overflow Error. Queue is Full.\n";
        return ;
    }

    Queue[Rear] = Data;
    cout << Queue[Rear] << " has been inserted at the end of the queue.\n";
    Rear++;
}

void Q_Delete()
{
    if(Front == Rear)
    {
        cout << "Underflow Error. Queue is empty.\n";
        return ;
    }

    Rear--;
    cout << Queue[Rear] << " has been deleted.\n";
}

void Q_Display()
{
    if(Front == Rear)
    {
        cout << "Underflow Error. Queue is empty.\n";
        return ;
    }

    cout << "The elements of the queue are : ";
    for(int i = Front ; i < Rear ; i++)
    {
        cout << Queue[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    Q_Delete();
    Q_Insert(1);
    Q_Insert(2);
    Q_Insert(3);
    Q_Insert(4);
    Q_Insert(5);
    Q_Insert(6);
    Q_Delete();
    Q_Display();
    return 0;
}

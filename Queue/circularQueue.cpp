//A program to implement the circular queue.
# include <iostream>
# define SIZE 3 //Maximum size of the queue

using namespace std;

int Queue[SIZE];
int Front = -1, Rear = -1;

void Q_Insert(int x)
{
    //First condition checks if the queue is full in the traditional way.
    //Second condition is the circular queue condition in which Front is ahead by Rear by 1.
    if((Front == 0 && Rear == SIZE - 1) || (Rear + 1 == Front))
    {
        cout << "Insertion not possible. Queue is full.\n";
        return ;
    }

    if(Front == -1 && Rear == -1) //If queue is initially empty
    {
        Front = Rear = 0;
    }
    else if(Front > 0 && Rear == SIZE - 1) //Else, check if rear has reached it's limit and front hasn't.
    {
        Rear = 0; //In such a case, set Rear = 0 again.
    }
    else
    {
        Rear++; //Else, just increment Rear
    }
    Queue[Rear] = x;
    cout << x << " has been inserted into the queue.\n";
}

void Q_Delete()
{
    if(Front == -1) //Check if the queue is initially empty.
    {
        cout << "\nDeletion not possible. Queue is empty.\n";
        return ;
    }

    cout << "\n" << Queue[Front] << " has been deleted.\n";
    if(Front == Rear) //If there is only one element in the queue,
    {
        Front = Rear = -1;
    }
    else if(Front == SIZE - 1) //The circular queue condition
    {
        Front = 0;
    }
    else //Else, just increment Front so that Arr[Front] is now longer a part of the queue.
    {
        Front++;
    }
}

void Q_Display()
{
    if(Front == -1)
    {
        cout << "No elements to Display. Queue is empty.\n";
        return ;
    }

    cout << "\nThe elements of the queue are : ";

    if(Rear >= Front)
    {
        for(int i = Front ; i < SIZE ; i++)
        {
            cout << Queue[i] << " ";
        }
    }

    else
    {
        for(int i = Front ; i < SIZE ; i++)
        {
            cout << Queue[i] << " ";
        }
        for(int i = 0 ; i <= Rear ; i++)
        {
            cout << Queue[i] << " ";
        }
    }

    cout << "\n";
}

void Menu()
{
    int Choice = 0;
    while(Choice != 4)
    {
        cout << "\nChoose Any One Of The Following Choices:-"
             << "\n1. Insert Into The Queue"
             << "\n2. Delete From The Queue"
             << "\n3. Display Elements Of The Queue"
             << "\n4. Exit"
             << "\nYour choice is : ";
        cin >> Choice;
        switch(Choice)
        {
            case 1 : {
                     int x;
                     cout << "\nEnter the element to be inserted : ";
                     cin >> x;
                     Q_Insert(x);
                      break;
                     }

          case 2 : Q_Delete();
                    break;

          case 3 : Q_Display();
                    break;

          case 4 : break;

          default : cout << "\nInvalid Choice.\n";
        }
    }
}

int main(void)
{
    Menu();
    return 0;
}

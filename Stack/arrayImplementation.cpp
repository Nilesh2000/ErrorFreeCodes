#include <iostream>
#define SIZE 5

int Stack[SIZE];
int Top = -1;

using namespace std;

void pushData(int x)
{
    if (Top == SIZE - 1)
    {
        cout << "Overflow error. Stack is already full.\n";
        return;
    }
    Top++;
    Stack[Top] = x;
    cout << "\n"
         << x << " has been pushed into the stack.\n";
}

void popData()
{
    if (Top == -1)
    {
        cout << "\nUnderflow error. Stack is empty.\n";
        return;
    }
    cout << "\n"
         << Stack[Top] << " has been popped.\n ";
    Top--;
}

void peek()
{
    if (Top == -1)
    {
        cout << "\nUnderflow error. Stack is empty.\n";
        return;
    }
    cout << "\n"
         << Stack[Top] << " is the topmost element of the stack.\n";
}

void displayStack()
{
    if (Top == -1)
    {
        cout << "\nUnderflow error. Stack is empty.\n";
        return;
    }
    cout << "\nThe elements of the stack are : ";
    for (int i = Top; i >= 0; i--)
    {
        cout << Stack[i] << " ";
    }
    cout << "\n";
}

void Menu()
{
    int Choice;
    while (Choice != 5)
    {
        cout << "\nChoose any one of the following choices:-"
             << "\n1. Push data into the stack"
             << "\n2. Pop data from the stack"
             << "\n3. Peek into the stack"
             << "\n4. Display the elements of the stack"
             << "\n5. Exit"
             << "\nYour choice is : ";
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            int Data;
            cout << "\nEnter the element to be pushed : ";
            cin >> Data;
            pushData(Data);
            break;

        case 2:
            popData();
            break;

        case 3:
            peek();
            break;

        case 4:
            displayStack();
            break;

        case 5:
            break;

        default:
            cout << "\nInvalid choice.\n";
        }
    }
}

int main(void)
{
    Menu();
    return 0;
}

//A program to implement two stacks in a single array given the the number of two stacks initially.
# include <iostream>

using namespace std;

class twoStacks
{
    int *Stack;
    int Size1, Size2;
    int Top1, Top2;

  public:

    twoStacks(int n1, int n2)
    {
        Size1 = n1;
        Size2 = n2;
        Stack = new int[n1 + n2];
        Top1 = -1;
        Top2 = Size1 - 1;
    }

    void pushStack1(int Data)
    {
        if(Top1 == Size1 - 1)
        {
            cout << "Stack 1 is full. Push operation not possible.";
            return ;
        }

        Top1++;
        Stack[Top1] = Data;
        cout << Stack[Top1] << " has been pushed into stack 1.";
    }

    void pushStack2(int Data)
    {
      if(Top2 == Size1 + Size2 - 1)
      {
          cout << "Stack 2 is full. Push operation not possible.\n";
          return ;
      }

      Top2++;
      Stack[Top2] = Data;
      cout << Stack[Top2] << " has been pushed into stack 2.\n";
    }

    void popStack1()
    {
        if(Top1 == -1)
        {
            cout << "\nStack 1 is empty. No elements to pop.\n";
            return ;
        }

        cout << "\n" << Stack[Top1] << " has been popped from stack 1.\n";
        Top1--;
    }

    void popStack2()
    {
        if(Top2 == Size1 - 1)
        {
          cout << "\nStack 2 is empty. No elements to pop.\n";
          return ;
        }

        cout << "\n" << Stack[Top2] << " has been popped from stack 2.\n";
        Top2--;
    }

    void displayStack1()
    {
      if(Top1 == -1)
      {
          printf("\nStack 1 is empty. No elements to display.\n");
          return ;
      }

      cout << "\nThe elements of stack 1 are : ";
      for(int i = Top1 ; i >= 0 ; i--)
      {
          cout << Stack[i] << " ";
      }
    }

    void displayStack2()
    {
      if(Top2 == Size1 - 1)
      {
        cout << "\nStack 2 is empty. No elements to display.\n";
        return ;
      }

      cout << "\nThe elements of stack 2 are : ";
      for(int i = Top2 ; i >= Size1 ; i--)
      {
          cout << Stack[i] << " ";
      }
    }

};

void Menu()
{
    int Size1, Size2, Choice = 0;
    cout << "\nEnter the sizes of stack 1 and stack 2 respectively : ";
    cin >> Size1 >> Size2;
    twoStacks Obj(Size1, Size2);

    while(Choice != 7)
    {
      cout <<   "\n\nChoose any one of the following choices:-"
           <<   "\n1. Push into stack 1"
           <<   "\n2. Push into stack 2"
           <<   "\n3. Pop from stack 1"
           <<   "\n4. Pop from stack 2"
           <<   "\n5. Display elements of stack 1"
           <<   "\n6. Display elements of stack 2"
           <<   "\n7. Exit"
           <<   "\nYour choice is : ";
       cin >> Choice;
      switch(Choice)
      {
          case 1 : {
                     int x;
                     cout << "\nEnter the element to be pushed into stack 1 : ";
                     cin >> x;
                     Obj.pushStack1(x);
                      break;
                   }

          case 2 : {
                     int y;
                     cout << "\nEnter the element to be pushed into stack 2 : ";
                     cin >> y;
                     Obj.pushStack2(y);
                      break;
                   }

          case 3 : Obj.popStack1();
                    break;

          case 4 : Obj.popStack2();
                    break;

          case 5 : Obj.displayStack1();
                    break;

          case 6 : Obj.displayStack2();
                    break;

          case 7 : break;

          default : cout << "\nInvalid choice.\n";
      }
    }
}

int main(void)
{
    Menu();
    return 0;
}

# include <iostream>
# include <cstdio>

using namespace std;

struct Node
{
    int Data;
    Node *Next;
};

Node *Head = NULL;

int lengthOfList()
{
    int Len = 1;
    Node *Temp = Head;
    while(Temp != NULL)
    {
        Len++;
        Temp = Temp -> Next;
    }
    return Len;
}

void insertIntoList(int x, int Pos)
{
    Node *Temp1;
    Temp1 = new Node();
    Temp1 -> Data = x;
    if(Pos == 1)
    {
        Temp1 -> Next = Head;
        Head = Temp1;
        return ;
    }
    Node *Temp2 = Head;
    for(int i = 1 ; i < Pos - 1 ; i++)
      {
          Temp2 = Temp2 -> Next;
      }
    Temp1 -> Next = Temp2 -> Next;
    Temp2 -> Next = Temp1;
}

void insertMenu()
{
    int Choice = 0, Pos, Num;
    cout << "\n1. Insert At Beginning"
         << "\n2. Insert At Nth Position"
         << "\n3. Insert At End"
         << "\nYour Choice is : ";
    cin >> Choice;
    cout << "\nEnter The Element To Insert : ";
    cin >>  Num;
     switch(Choice)
     {
              case 1 :  Pos = 1;
                         break;

              case 2 : cout << "Enter The Position For Insertion : ";
                       cin >> Pos;
                        break;

              case 3 : Pos = lengthOfList();
                        break;
      }
    insertIntoList(Num, Pos);
}

void deleteByPos(int n)
{
    Node *Temp1 = Head;
    if(n == 1)
    {
        Head = Temp1 -> Next;
        delete Temp1;
        return ;
    }
    for(int i = 1 ; i < n - 1 ; i++)
    {
        Temp1 = Temp1 -> Next;
    }
    Node *Temp2 = Temp1 -> Next;
    Temp1 -> Next = Temp2 -> Next;
    delete Temp2;
}

void deletePosMenu()
{
    int Choice, Pos;
    cout << "\n1. Delete at the beginning"
         << "\n2. Delete at Nth Position"
         << "\n3. Delete at the end"
         << "\nYour choice is : ";
    cin >> Choice;
    switch(Choice)
    {
        case 1 : Pos = 1;
                  break;

        case 2 : cout << "\nEnter Position For Deletion : ";
                 cin >> Pos;
                  break;

        case 3 : Pos = lengthOfList();
                  break;
    }
    deleteByPos(Pos);
}

void deleteData(int x)
{
    Node *Temp = Head, *Prev;
    if(Temp != NULL && Temp -> Data == x)
    {
        Head = Temp -> Next;
        delete Temp;
        return ;
    }
    while(Temp != NULL && Temp -> Data != x)
    {
            Prev = Temp;
            Temp = Temp -> Next;
    }
    if(Temp == NULL)
    {
        cout << "\nElement not found in the list.";
        return ;
    }
    Prev -> Next = Temp -> Next;
    delete Temp;
}

void deleteMenu()
{
    int Choice, Num;
    cout << "\n1. Delete By Position"
         << "\n2. Delete By Element"
         << "\nYour choice is : ";
    cin >> Choice;
    switch(Choice)
    {
        case 1 : deletePosMenu();
                  break;

        case 2 : cout << "\nEnter the element to delete : ";
                 cin >> Num;
                 deleteData(Num);
                  break;

        default : cout << "\nInvalid choice.";
    }
}

void removeDuplicates()
{
    Node *Ptr1 = Head, *Ptr2, *Dup;
    while(Ptr1 != NULL && Ptr1 -> Next != NULL)
    {
        Ptr2 = Ptr1;
        if(Ptr1 -> Data == Ptr2 -> Next -> Data)
        {
            Dup = Ptr2 -> Next;
            Ptr2 -> Next = Ptr2 -> Next -> Next;
            delete Dup;
        }
        else
        {
            Ptr2 = Ptr2 -> Next;
        }
        Ptr1 = Ptr1 -> Next;
    }
}

void reverseIterate()
{
    Node *Prev, *Cur, *Next;
    Prev = NULL;
    Cur = Head;
    while(Cur != NULL)
    {
        Next = Cur -> Next;
        Cur -> Next = Prev;
        Prev = Cur;
        Cur = Next;
    }
    Head = Prev;
}

void reverseMenu()
{
    int Choice;
    cout << "\n1. Reverse Using Iteration"
         << "\n2. Reverse Using Recursion"
         << "\nYour choice is : ";
    cin >> Choice;
    switch(Choice)
    {
        case 1 : reverseIterate();
                  break;

        case 2 : //reverseRecursive();
                  break;

        default : cout << "\nInvalid choice.";
    }
}

int middleOfList()
{
    Node *Slow_Ptr = Head, *Fast_Ptr = Head;
    while(Fast_Ptr != NULL && Fast_Ptr -> Next != NULL)
    {
        Fast_Ptr = Fast_Ptr -> Next -> Next;
        Slow_Ptr = Slow_Ptr -> Next;
    }
    return Slow_Ptr -> Data;
}

void displayList()
{
    if(Head == NULL)
    {
        cout << "\nNo elements to display.";
        getchar();
        return ;
    }
    Node *Temp = Head;
    cout << "\nThe elements of the list : ";
    while(Temp != NULL)
    {
        cout << Temp -> Data << " ";
        Temp = Temp -> Next;
    }
    cout << endl;
}

int lengthOfLoop(Node *n)
{
    int lenOfLoop = 1;
    Node *Temp = n;
    while(Temp -> Next != n)
    {
        lenOfLoop++;
        Temp = Temp -> Next;
    }
    return lenOfLoop;
}

void detectLoop()
{
    Node *Slow_Ptr = Head, Fast_Ptr = Head;
    while(Fast_Ptr != NULL && Fast_Ptr -> Next = NULL)
    {
        Slow_Ptr = Slow_Ptr -> Next;
        Fast_Ptr = Fast_Ptr -> Next;
        if(Slow_Ptr == Fast_Ptr)
        {
            cout << "\nA loop exists in the list and it's length is : " << lengthOfLoop(Slow_Ptr) << endl;
            return ;
        }
    }
  cout << "\nNo loop exists in the linked list." << endl;
}

void Menu()
{
    int Choice = 0;
    while(1)
      {
          cout << "\n1. Insert Into List"
               << "\n2. Delete From List"
               << "\n3. Count of Elements In The List"
               << "\n4. Remove duplicates from the list"
               << "\n5. Reverse the list"
               << "\n6. Display middle element of the list"
               << "\n7. Display The Elements Of The List"
               << "\n8. Check for loop in list"
               << "\n9. Exit"
               << "\nYour choice is : ";
          cin >> Choice;
          switch(Choice)
          {
              case 1 : insertMenu();
                        break;

              case 2 : deleteMenu();
                        break;

              case 3 : cout << "\nThe number of elements in the list is : " << lengthOfList() - 1 << endl;
                        break;

              case 4 : removeDuplicates();
                        break;

              case 5 : reverseMenu();
                        break;

              case 6 : cout << "\nThe middle element of the list is : " << middleOfList() << endl;
                        break;

              case 7 : displayList();
                        break;

              case 8 : detectLoop();
                        break;

              case 9 : exit(0);

              default : cout << "\nInvalid choice.\n";
          }
      }
}

int main(void)
{
    Menu();
    return 0;
}

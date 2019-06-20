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
            delete(Dup);
        }
        else
        {
            Ptr2 = Ptr2 -> Next;
        }
        Ptr1 = Ptr1 -> Next;
    }
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
void Menu()
{
    int Choice = 0;
    while(Choice != 15)
      {
          cout << "\n1. Insert Into List"
               << "\n2. Count of Elements In The List"
               << "\n3. Remove duplicates from the list"
               << "\n4. Display The Elements Of The List"
               << "\n5. Exit"
               << "\nYour choice is : ";
          cin >> Choice;
          switch(Choice)
          {
              case 1 : insertMenu();
                        break;

              case 2 : cout << "\nThe number of elements in the list is : " << lengthOfList();
                        break;

              case 3 : removeDuplicates();
                        break;

              case 4 : displayList();
                        break;

              case 5 : exit(0);

              default : cout << "\nInvalid choice.\n";
          }
      }
}

int main(void)
{
    Menu();
    return 0;
}

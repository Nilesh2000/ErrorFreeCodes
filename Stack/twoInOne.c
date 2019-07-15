//A program to accomadate to two stacks into a single stack data structure with an array implementation.
# include <stdio.h>
# include <math.h>
# define SIZE 10

int Stack[SIZE];
int Top1 = -1;
int Top2 = SIZE;

void pushStack1(int Data)
{
    if(abs(Top1 - Top2) == 1)
    {
        printf("\nStack is full. Push operation not possible.");
        return ;
    }

    Top1++;
    Stack[Top1] = Data;
    printf("%d has been pushed into stack 1.\n", Stack[Top1]);
}

void pushStack2(int Data)
{
  if(abs(Top1 - Top2) == 1)
  {
      printf("\nStack is full. Push operation not possible.");
      return ;
  }

  Top2--;
  Stack[Top2] = Data;
  printf("%d has been pushed into stack 2.\n", Stack[Top2]);
}

void popStack1()
{
    if(Top1 == -1)
    {
        printf("\nStack 1 is empty. No elements to pop.\n");
        return ;
    }

    printf("\n%d has been popped.", Stack[Top1]);
    Top1--;
}

void popStack2()
{
    if(Top2 == SIZE)
    {
      printf("\nStack 2 is empty. No elements to pop.\n");
      return ;
    }

    printf("\n%d has been popped.", Stack[Top2]);
    Top2++;
}

void displayStack1()
{
  if(Top1 == -1)
  {
      printf("\nStack 1 is empty. No elements to display.\n");
      return ;
  }

  printf("\nThe elements of stack 1 are : ");
  for(int i = Top1 ; i >= 0 ; i--)
  {
      printf("%d ", Stack[i]);
  }
  printf("\n");
}

void displayStack2()
{
  if(Top2 == SIZE)
  {
    printf("\nStack 2 is empty. No elements to display.\n");
    return ;
  }

  printf("\nThe elements of stack 2 are : ");
  for(int i = Top2 ; i < SIZE ; i++)
  {
      printf("%d ", Stack[i]);
  }
  printf("\n");
}

void Menu()
{
    int Choice;
    while(Choice != 7)
    {
      printf(
             "\nChoose any one of the following choices:-"
             "\n1. Push into stack 1"
             "\n2. Push into stack 2"
             "\n3. Pop from stack 1"
             "\n4. Pop from stack 2"
             "\n5. Display elements of stack 1"
             "\n6. Display elements of stack 2"
             "\n7. Exit"
             "\nYour choice is : "
             );
      scanf("%d", &Choice);
      switch(Choice)
      {
          case 1 : {
                     int x;
                     printf("\nEnter the element to be pushed into stack 1 : ");
                     scanf("%d", &x);
                     pushStack1(x);
                      break;
                   }

          case 2 : {
                     int y;
                     printf("\nEnter the element to be pushed into stack 2 : ");
                     scanf("%d", &y);
                     pushStack2(y);
                      break;
                   }

          case 3 : popStack1();
                    break;

          case 4 : popStack2();
                    break;

          case 5 : displayStack1();
                    break;

          case 6 : displayStack2();
                    break;

          case 7 : break;

          default : printf("\nInvalid choice.\n");
      }
    }
}

int main(void)
{
    Menu();
    return 0;
}

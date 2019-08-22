# include <stdio.h>
# include <string.h>
# define MAX 5

char Queue[MAX][10];
int Front = -1, Rear = -1;

void deleteMessage()
{
    if(Front == -1)
    {
        printf("\nNo messages to delete.");
        return ;
    }

    if(Front == Rear)
      Front = Rear = -1;
    else if(Front == MAX - 1)
      Front = 0;
    else
      Front++;
}

void addMessage(char s[])
{
    if((Front == 0 && Rear == MAX - 1) || (Rear + 1 == Front))
    {
        deleteMessage();
    }

    if(Front == -1 && Rear == -1)
      Front = Rear = 0;

    else if(Front > 0 && Rear == MAX - 1)
      Rear = 0;

    else
      Rear++;

    strcpy(Queue[Rear], s);
}

void displayMessage()
{
  if(Front == -1)
  {
      printf("No messages to display.\n");
      return ;
  }

  printf("\nThe elements of the queue are : ");

  if(Rear >= Front)
  {
      for(int i = Front ; i < MAX ; i++)
      {
          printf("%s ", Queue[i]);
      }
  }

  else
  {
      for(int i = Front ; i < MAX ; i++)
      {
          printf("%s ", Queue[i]);
      }
      for(int i = 0 ; i <= Rear ; i++)
      {
          printf("%s ", Queue[i]);
      }
  }
  printf("\n");
}

void Menu()
{
    int Choice;
    char Str[10];
    while(Choice != 4)
    {
        printf("\n1. Add a new message"
               "\n2. Delete a message"
               "\n3. Display all messages"
               "\n4. Exit"
               "\nYour choice is : ");
        scanf("%d", &Choice);
        switch(Choice)
        {
            case 1 : scanf("%s", Str);
                     addMessage(Str);
                      break;

            case 2 : deleteMessage();
                      break;

            case 3 : displayMessage();
                      break;

            case 4 : break;
        }
    }
}

int main(void)
{
    Menu();
    return 0;
}

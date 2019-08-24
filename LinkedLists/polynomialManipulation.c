//A program to add two polynomials using linked lists.
# include <stdio.h>
# include <stdlib.h>

// Node structure containing Power and Coefficient of variable
struct Node
{
	int Coeff;
	int Pow;
	struct Node *Next;
};

// Function to create new node
void create_node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if(z == NULL)
    {
        r =(struct Node*)malloc(sizeof(struct Node));
        r->Coeff = x;
        r->Pow = y;
        *temp = r;
        r->Next = (struct Node*)malloc(sizeof(struct Node));
        r = r->Next;
        r->Next = NULL;
    }
    else
    {
        r->Coeff = x;
        r->Pow = y;
        r->Next = (struct Node*)malloc(sizeof(struct Node));
        r = r->Next;
        r->Next = NULL;
    }
}

// Function Adding two polynomial numbers
void addPoly(struct Node *Poly1, struct Node *Poly2, struct Node *Poly)
{
  while(Poly1->Next && Poly2->Next)
	{
		// If Power of 1st polynomial is greater then 2nd, then store 1st as it is
		// and move its pointer
		if(Poly1->Pow > Poly2->Pow)
		{
			Poly->Pow = Poly1->Pow;
			Poly->Coeff = Poly1->Coeff;
			Poly1 = Poly1->Next;
		}

		// If Power of 2nd polynomial is greater then 1st, then store 2nd as it is
		// and move its pointer
		else if(Poly1->Pow < Poly2->Pow)
		{
			Poly->Pow = Poly2->Pow;
			Poly->Coeff = Poly2->Coeff;
			Poly2 = Poly2->Next;
		}

		// If Power of both polynomial numbers is same then add their Coefficients
		else
		{
			Poly->Pow = Poly1->Pow;
			Poly->Coeff = Poly1->Coeff+Poly2->Coeff;
			Poly1 = Poly1->Next;
			Poly2 = Poly2->Next;
		}

		// Dynamically create new node
		Poly->Next = (struct Node *)malloc(sizeof(struct Node));
		Poly = Poly->Next;
		Poly->Next = NULL;
	}
  while(Poly1->Next || Poly2->Next)
	{
		if(Poly1->Next)
		{
			Poly->Pow = Poly1->Pow;
			Poly->Coeff = Poly1->Coeff;
			Poly1 = Poly1->Next;
		}

		if(Poly2->Next)
		{
			Poly->Pow = Poly2->Pow;
			Poly->Coeff = Poly2->Coeff;
			Poly2 = Poly2->Next;
		}

		Poly->Next = (struct Node *)malloc(sizeof(struct Node));
		Poly = Poly->Next;
		Poly->Next = NULL;
	}

}

void show(struct Node *Node)
{
  while(Node -> Next != NULL)
	{
	   printf("%dx^%d", Node->Coeff, Node->Pow);
	    Node = Node -> Next;
	     if(Node -> Next != NULL)
		     printf(" + ");
	}
}

int main(void)
{
	struct Node *Poly1 = NULL, *Poly2 = NULL, *Poly = NULL;

	// Create first list of 5x^2 + 4x^1 + 2x^0
	create_node(5,2,&Poly1);
	create_node(4,1,&Poly1);
	create_node(2,0,&Poly1);
	// Create second list of 5x^1 + 5x^0
	create_node(5,1,&Poly2);
	create_node(5,0,&Poly2);

	show(Poly1);
  printf("\n");
	show(Poly2);

	Poly = (struct Node *)malloc(sizeof(struct Node));
	// Function add two polynomial numbers
	addPoly(Poly1, Poly2, Poly);
	// Display resultant List
	printf("\nAdded polynomial: ");
	show(Poly);

  return 0;
}

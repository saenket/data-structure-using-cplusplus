/* C++ Linked Lists - Example Program of Linked Lists
 * Deletion from the beginning of the list.
 * This program first creates the linked list, then
 * allows user to delete nodes from the beginning
 * of the list */

#include<iostream.h>
#include<conio.h>
#include<process.h>

struct node
{
	int info;
	node *next;
} *start, *newptr, *save, *ptr, *rear;

node *create_new_node(int);
void insert_node(node *);
void display_node(node *);
void delete_node();

void main()
{
	clrscr();
	start = rear = NULL;
	int inf;
	char ch='y';

	while(ch=='y' || ch=='Y')
	{
		clrscr();
		cout<<"Enter Information for the new node: ";
		cin>>inf;
		newptr = create_new_node(inf);
		if(newptr == NULL)
		{
			cout<<"\nSorry..!!..cannot create new node..!!..Aborting..!!";
			cout<<"\nPress any key to exit..";
			getch();
			exit(1);
		}
		insert_node(newptr);
		cout<<"\nWant to enter more nodes ? (y/n)..";
		cin>>ch;
	}
	clrscr();
	do
	{
		cout<<"The list now is:\n";
		display_node(start);
		cout<<"\nWant to delete first node ? (y/n)..";
		cin>>ch;
		if(ch=='y' || ch=='Y');
		{
			delete_node();
		}
	}while(ch=='y' || ch=='Y');
	getch();
}

node *create_new_node(int n)
{
	ptr = new node;
	ptr->info = n;
	ptr->next = NULL;
	return ptr;
}

void insert_node(node *np)
{
	if(start==NULL)
	{
		start = rear = np;
	}
	else
	{
		rear -> next = np;
		rear = np;
	}
}

void delete_node()
{
	if(start == NULL)
	{
		cout<<"Underflow...!!\n";
	}
	else
	{
		ptr = start;
		start = start->next;
		delete ptr;
	}
}

void display_node(node *np)
{
	while(np != NULL)
	{
		cout<<np->info<<" -> ";
		np = np->next;
	}
	cout<<"!!\n";
}

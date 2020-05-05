#include<iostream>
using namespace std;

typedef struct node
{
	struct node *next,*prev;
	int data;
};

class list 
{
	node *head,*tail;
	
	public:
	list()
	{
		head = NULL;
		tail = NULL;
	}
	
	node* getNode(node*);
	node* createDLL(node*,int);
	void display(node*);
};

node* list::getNode(node *nev)
{
	nev = new node;
	nev->next = NULL;
	nev->prev = NULL;
	
	return nev;
}

node* list::createDLL(node *head,int n)
{	
	if(head==NULL)
	{
		node *nev = getNode(nev);	 
		cout<<"Enter a data: ";
		cin>>nev->data;
		head = nev;
		tail = nev;
	}
	
	for(int i=1;i<n;i++)
	{
		node *nev = getNode(nev);	 
		cout<<"Enter a data: ";
		cin>>nev->data;
		tail->next = nev;
		nev->prev = tail;
		tail = nev;
	}
	return head;
}

void list::display(node* head)
{
	node *temp;
	temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{
	int n,ch;
	list l;
	node *head;
	head=NULL;
	
	cout<<"Enter the number of nodes you want to create: ";
	cin>>n;
	head = 	l.createDLL(head,n);
	cout<<"\nThe list is: ";
	l.display(head);
	
	return 0;
}
	

			
				

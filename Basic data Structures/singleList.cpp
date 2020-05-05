#include<iostream>
using namespace std;

struct node
{
	
	int data;
	node *next;
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
	
	void add_start(int);
	void add_last(int);
	void display();
	void add_position(int,int);
	void delete_first();
	void delete_last();
	void delete_position(int);
};

//insertion at start
void list::add_start(int value)
{
	node *temp = new node;
	temp->data = value;
	temp->next = head;	
	head = temp;
}

//insertion at last
void list ::add_last(int value)
{
	node *temp = new node;
	temp->data = value;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	} 
}

//insertion at any position
void list::add_position(int pos,int value)
{
	int i;
	node *pre = new node;
	node *cur = new node;
	node *temp = new node;	
	cur = head;	
	for(i=1;i<pos;i++)
	{
		pre = cur;
		cur = cur->next;
	}
	temp->data = value;
	pre->next = temp;	
	temp->next = cur;
}	

void list::display()
{
	node *ptr;
	ptr = head;	
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" "<<endl;
		ptr = ptr->next;
	}
}

//deletion at first node
void list::delete_first()
{
	node *temp = new node;
	temp = head;
	head = head->next;
	delete temp;
}

//deletion at last
void list::delete_last()
{
	node *pre = new node;
	node *cur = new node;
	cur = head;
	while(cur->next!=NULL)
	{
		pre = cur;
		cur = cur->next;
	}
	tail = pre;
	pre->next = NULL;
	delete cur;
}

//delete at any postion
void list::delete_position(int pos)
{
	int i;
	node *pre = new node;
	node *cur = new node;
	cur = head;
	for(i=1;i<pos;i++)
	{
		pre = cur;
		cur = cur->next;
	}
	pre->next = cur->next;
	delete cur;
}
	

int main()
{
	list l;
	int i,n;
	for(i=0;i<11;i++)
	{
		l.add_last(i);		

	}
	l.display();
	cout<<endl;
	l.delete_position(4);
	//l.delete_last();
	//l.add_position(5,50);
	l.display();
    
	return 0;
}
	
	

#include<iostream>
using namespace std;

#define MAX 100
class stack
{
	int a[20];
	int top;
	
	public:
	stack()
	{
		top = -1;
	}
	
	void push(int);
	void display();
	void pop();
	void isFull(int);
	void isEmpty();
};

void stack::push(int data)
{
	if(top == MAX-1)
	{
		cout<<"Stack overflow"<<endl;
	}
	else
	{
		a[top+1] = data;
		top++;
	}
}

void stack::display()
{
	int i;
	for(i=0;i<top+1;i++)
	{
		cout<<a[i]<<endl;;
	}
}

void stack::pop()
{
	if(top==-1)
	{
		cout<<"Stack Underflow"<<endl;
	}
	else
	{
		top = top-1;
	}
}

void stack::isFull(int n)
{
	if(top==n-1)
	{
		cout<<"Stack Overflow"<<endl;
	}
	else
	{
		cout<<"You can push an element "<<endl;
	}
}

void stack::isEmpty()
{
	if(top==-1)
	{
		cout<<"Stack Underflow"<<endl;
	}
	else
	{
		cout<<"You can pop an element "<<endl;
	}
}		
	
int main()
{
	stack st;
	int i;
	
	for(i=0;i<10;i++)
	{
		st.push(i);
	}
	
	st.display();
	cout<<endl;
	for(i=0;i<5;i++)
	{
		st.pop();
	}
	st.display();
	return 0;
}



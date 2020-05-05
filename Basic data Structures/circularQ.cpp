#include<iostream>
using namespace std;

#define MAX 100

class queue
{
	int a[MAX],rear,front;
	
	public:
	queue()
	{
		rear = -1;
		front = -1;
	}
	
	void enqueue(int);
	void dequeue();
	void display();
	
};


void queue::enqueue(int data)
{
	if(rear==-1)
	{
		rear++;
		front++;
		a[rear] = data;
	}
	else if(rear==MAX-1 && front!=0)
	{
		rear = 0;
		a[rear]=data;
	}		
	else 
	{
		rear++;
		a[rear] = data;
	}
}

void queue::dequeue()
{
	if(front==-1 || front==rear+1)
	{
		cout<<"Queue is empty"<<endl;
	}
	else if(front==MAX-1)
	{
		front=0;
		int m = MAX;
		m--;
	}
	else
	{
		front++;
	}
}

void queue::display()
{
	int i;
	for(i=front;i<=rear;i++)
	{
		cout<<a[i]<<endl;
	}
}

int main()
{
	int i,n;
	queue q;
	cout<<"Enter the number of elements in queue:"<<endl;
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		q.enqueue(i+1);
	}
	
	cout<<"\nThe elements are:"<<endl;	
	q.display();
	
	cout<<endl;
	
	q.dequeue();
	q.dequeue();
	q.dequeue();
	
	q.display();

	return 0;
}

	

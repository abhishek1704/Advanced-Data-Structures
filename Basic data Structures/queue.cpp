#include<iostream>
using namespace std;

#define MAX 100
class queue
{
	int a[MAX];
	int front,rear;
	
	public:
	queue()
	{
		front = -1;
		rear = -1;
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
	else
	{
		rear++;
		a[rear] = data;
	}
}

void queue::dequeue()
{
	if(front==-1)
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{	
		front+=1;
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
	queue q;
	int i;
	
	for(i=0;i<10;i++)
	{
		q.enqueue(i);
	}
	cout<<"Complete queue:"<<endl;
	q.display();
 	q.dequeue();
 	q.dequeue();
	cout<<"\nQueue after dequeue operation:"<<endl;
	q.display();
}


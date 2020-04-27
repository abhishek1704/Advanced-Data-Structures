/*
 * Graph.cpp
 *
 *  Created on: 02-Mar-2020
 *      Author: dsflh-9
 */
#include "Graph.h"
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

Graph::Graph() {
	head = NULL;
	// TODO Auto-generated constructor stub

}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

node1* Graph::getNode(node1 *p)
{
	cout<<"Enter the name of user: ";
	cin>>p->name;
	cout<<"Enter the date of birth: "<<endl;
	cout<<"Date: ";
	cin>>p->dob.date;
	cout<<"Month: ";
	cin>>p->dob.month;
	cout<<"Year: ";
	cin>>p->dob.year;

	return p;
}

void Graph::create(int i)
{
	node1 *p = new node1;

	p = getNode(p);
	p->v = i;

	if(head==NULL)
	{
		head = p;
		return;
	}

	node1 *temp = head;
	while(temp->dlink!=NULL)
	{
		temp = temp->dlink;
	}

	temp->dlink = p;
}

void Graph::createLink()
{
	string fname;
	int f;
	node1 *n1 = new node1;
	node1 *n2 = new node1;
	n1 = n2= head;
	while(n1!=NULL)
	{
		cout<<"\nAdd friends of "<<n1->name<<endl;
		n2 = head;
		while(n2!=NULL)
		{
			if(n2->name!=n1->name)
			{
				cout<<"\nDo "<<n2->name<<" friend of "<<n1->name<<"?"<<endl;
				cout<<"Press 1 if yes 0 if no: ";
				cin>>f;
				if(f)
				{
					node2 *p = new node2;
					p->next = NULL;
					p->ptr = n2;
					cout<<"\nEnter the comments from "<<n2->name<<" :";
					cin>>p->c;
					if(n1->next==NULL)
					{
						n1->next = p;
					}
					else
					{
						node2 *temp = n1->next;

						while(temp->next!=NULL)
						{
							temp = temp->next;
						}
						temp->next = p;
					}
				}
			}
			n2 = n2->dlink;
		}
		n1 = n1->dlink;
	}
}

void Graph::depthFirst()
{
	stack<node1*> st;
	int visit[10];

	for(int i=0;i<10;i++)
		visit[i] = 0;

	node1 *temp1 = head;
	node2 *temp2;

	st.push(temp1);

	while(!st.empty())
	{
		node1 *p = st.top();
		st.pop();
		if(p->dob.month==3)
		{
			cout<<endl;
			cout<<p->name<<" has birthday this month !"<<endl;
			cout<<"It's on "<<p->dob.date<<endl;
		}
		visit[p->v]=1;
		temp2 = temp1->next;
		while(temp2!=NULL && visit[temp2->ptr->v]!=1)
		{
			st.push(temp2->ptr);
			visit[temp2->ptr->v]=1;
			temp2 = temp2->next;
		}
	}
}

void Graph::breadthFirst()
{
	queue<node1*> q;
	int cnt=0;
	int visit[10];
	for(int i=0;i<10;i++)
		visit[i] = 0;
	node1 *temp1 = head;
	node2 *temp2;

	q.push(temp1);
	node1 *max = head;
	while(!q.empty())
	{
		node1* p = q.front();
		q.pop();

		visit[p->v] = 1;

		temp2 = temp1->next;
		while(temp2!=NULL)
		{
			if(visit[temp2->ptr->v]!=1)
			{
				q.push(temp2->ptr);
				visit[temp2->ptr->v]=1;
			}
			p->tcomments+=temp2->c;
			temp2 = temp2->next;
		}
		if(max->tcomments<p->tcomments)
		{
			max = p;
		}
	}

	cout<<endl;
	cout<<max->name<<" has maximum number of comments equal to "<<max->tcomments;

}

void Graph::maxFriends()
{
	int cnt;

	node1 *temp1 = head;
	node2 *temp2;
	node1* max = head;
	max->tfriends = 0;

	while(temp1!=NULL)
	{
		cnt=0;

		temp2 = temp1->next;
		while(temp2!=NULL)
		{
			temp2 = temp2->next;
			cnt++;
		}
		temp1->tfriends=cnt;
		if(temp1->tfriends>max->tfriends)
		{
			max=temp1;
		}
		temp1=temp1->dlink;
	}

	cout<<max->name<<" has the maximum number of friends !"<<endl;

}
void Graph::display()
{
	node1 *temp;
	node2 *temp1;
	temp = head;
	while(temp!=NULL)
	{
		cout<<temp->name<<" ";
		temp1 = temp->next;
		while(temp1!=NULL)
		{
			cout<<temp1->ptr->name<<" ";
			temp1 = temp1->next;
		}
		cout<<endl;

		temp = temp->dlink;
	}
}

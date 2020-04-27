/*
 * list.cpp
 *
 *  Created on: 18-Dec-2019
 *      Author: dsflh-9
 */

#include "list1.h"
#include<iostream>
using namespace std;

template<class M>
list1<M>::list1() {
	head = NULL;
	last = NULL;
	// TODO Auto-generated constructor stub
}

template<class M>
node<M>* list1<M>::insert(node<M>* head,M value)
{
	node<M> *p,*prev=NULL;
	M k;
	p = new node<M>;
	p->next = NULL;
	p->data = value;
	p->next = head;
	head = p;

	return head;
}

template<class M>
node<M>* list1<M>::delet(node<M>* head)
{
	if(head==NULL)
	{
		return head;
	}
	node<M> *temp = head;
	head = head->next;
	delete temp;

	return head;
}

template<class M>
int list1<M>::empty(node<M>* head)
{
	if(head==NULL)
		return 1;
	return 0;
}

template<class M>
void list1<M>::display(node<M> *head)
{
	node<M> *temp;
	temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

template<class M>
M list1<M>::dispHead(node<M> *head)
{
	if(head!=NULL)
	{
		return head->data;
	}
	else
		return 0;
}

template<class M>
list1<M>::~list1() {
	// TODO Auto-generated destructor stub
}


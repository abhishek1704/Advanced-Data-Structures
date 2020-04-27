/*
 * Queue.cpp
 *
 *  Created on: 13-Jan-2020
 *      Author: dsflh-9
 */

#include "Queue.h"
#include <iostream>
#include <iomanip>
using namespace std;

Queue::Queue()  // Constructor
{
	rear = NULL;
	front = NULL;
	// TODO Auto-generated constructor stub

}

int Queue::evalPriority(char p) // Function to get integer priority
{
	switch(p)
	{
	case 'S':
		return 1;
	case 'M':
		return 2;
	case 'G':
		return 3;
	}
	return 0;
}

node* Queue::getnode(node *nev) // Function to get patient's information
{
	char p;
	cout<<"\nEnter the name of the patient: "<<endl;
	cin>>nev->name;	

	cout<<"Enter date of birth of the patient: "<<endl;

	cout<<"Day: ";
	cin>>nev->d.day;
	while(nev->d.day<1 || nev->d.day>31)
	{
		cout<<"Enter the day again: ";
		cin>>nev->d.day;
	}

	cout<<"Month: ";
	cin>>nev->d.month;
	while(nev->d.month<1 || nev->d.month>12)
	{
		cout<<"Enter the month again: ";
		cin>>nev->d.month;
	}

	cout<<"Year: ";
	cin>>nev->d.year;
	while(nev->d.year<1900 || nev->d.year>2019)
	{
		cout<<"Enter the year again: ";
		cin>>nev->d.year;
	}

	cout<<"Enter the age of the patient: "<<endl;
	cin>>nev->age;
	cout<<"Enter the blood group: "<<endl;
	cin>>nev->bloodGrp;
	cout<<"Enter a disease :"<<endl;
	cin>>nev->dis;
	cout<<"Enter the priority:";
	cin>>p;
	nev->priority = evalPriority(p);		

	return nev;
}

void Queue::enqueue() // Function to create and insert a node in priority queue according to the priority by which he will be served
{
	node *nev,*temp;
	nev = new node;
	nev->next = NULL;
	nev = getnode(nev);

	if(front==NULL)
	{
		front=rear=nev;
		return;
	}

    // if the front of queue has lesser priority than new node, insert new node
    // node before front node and change front node. 

    if ((front)->priority > nev->priority)
    {
        // Insert New Node before front 
        nev->next = front; 
        (front) = nev; 
    } 
    else 
    { 
  		temp = front;
        // Traverse the list and find a 
        // position to insert new node 
        while (temp->next != NULL && temp->next->priority < nev->priority)
        {
            temp = temp->next; 
        } 
  
        // Insert a node either at the ends of the list
        // or at required position 
        nev->next = temp->next; 
        temp->next = nev;   
     } 	

}

void Queue::dequeue() // Function to delete a node at front
{
	if(front==NULL)
	{
		cout<<"No patient to serve !"<<endl;
		return;
	}
	node *temp = front;
	front = front->next;
	delete temp;
}

void Queue::display() // Display patient data according to the priority
{
	node *temp;
	temp = front;
	int i=1;
	
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<setw(12)<<"Name    "
	<<setw(8)<<"Age "
	<<setw(18)<<"DateOfBirth "
	<<setw(12)<<"BloodGrp"
	<<setw(12)<<"Disease "
	<<setw(12)<<"Priority"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
		
	while(temp!=NULL)
	{		
		cout<<setw(8)<<temp->name;
		cout<<setw(10)<<temp->age;
		cout<<setw(10)<<temp->d.day<<"-"<<temp->d.month<<"-"<<temp->d.year;
		cout<<setw(12)<<temp->bloodGrp;
		cout<<setw(12)<<temp->dis;
		cout<<setw(12)<<i<<endl<<endl;

		temp = temp->next;
		i++;
	}

	cout<<"---------------------------------------------------------------------------"<<endl;

}

Queue::~Queue() // Destructor
{
	// TODO Auto-generated destructor stub
}


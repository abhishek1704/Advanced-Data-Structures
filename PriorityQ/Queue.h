/*
 * Queue.h
 *
 *  Created on: 13-Jan-2020
 *      Author: dsflh-9
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include <string>
using namespace std;

class Queue;

class node
{
	string name;
	string bloodGrp;
	string dis;
	struct dob
	{
		int day,month,year;
	};

	struct dob d;
	int age;
	node *next;
	int priority;
	
public:
	friend class Queue;
};

class Queue {
	node *front,*rear;

public:
	Queue();
	node* getnode(node *nev);
	int evalPriority(char);
	void enqueue();
	void dequeue();
	void display();
	virtual ~Queue();
};

#endif /* QUEUE_H_ */

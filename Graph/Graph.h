/*
 * Graph.h
 *
 *  Created on: 02-Mar-2020
 *      Author: dsflh-9
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <string>
using namespace std;

class Graph;
class node2;

class node1
{
	string name;
	struct dateOfBirth
	{
		int date,month,year;
	};
	struct dateOfBirth dob;
	int tfriends,tcomments;
	node2 *next;
	node1 *dlink;
	int v;

public:
	friend class Graph;
};

class node2
{
	node1 *ptr;
	int c;
	node2 *next;
public:
	friend class Graph;
};

class Graph {
	node1 *head;
public:
	Graph();
	void create(int);
	node1* getNode(node1*);
	void display();
	void createLink();
	void maxFriends();
	void depthFirst();
	void breadthFirst();
	void maxComments();
	virtual ~Graph();
};


#endif /* GRAPH_H_ */

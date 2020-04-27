/*
 * Graph.h
 *
 *  Created on: 20-Mar-2020
 *      Author: abhishek
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#define MAX 50


class Graph {
	int g[MAX][MAX],v,e;
public:
	Graph();
	void create();
	void display();
	void dijkstra();
	void displaySolution(int[],int[],int);
	virtual ~Graph();

};

#endif /* GRAPH_H_ */

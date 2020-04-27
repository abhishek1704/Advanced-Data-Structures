/*
 * Graph.h
 *
 *  Created on: 30-Mar-2020
 *      Author: abhishek
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#define MAX 50

class Graph {

	int g[MAX][MAX],v,e,cost;
	struct edge
	{
		int src,dest,wt;
	};
	struct edge ed[MAX],T[MAX];

public:
	Graph();
	void create();
	void prims();
	void createMST(int[]);
	void displayGraph();
	void displayMST();
	virtual ~Graph();
};

#endif /* GRAPH_H_ */

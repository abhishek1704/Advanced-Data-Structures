/*
 * Graph.cpp
 *
 *  Created on: 30-Mar-2020
 *      Author: abhishek
 */

#include "Graph.h"
#include <iostream>
#include <iomanip>
#include <queue>
#define MAX_INT 1000000

using namespace std;

Graph::Graph() {

	v=e=cost=0;
	// TODO Auto-generated constructor stub

}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

string stringOf(int num) // Function will return corresponding name for the vertex
{
	switch(num)
	{
	case 0:
		return "India";

	case 1:
		return "USA";

	case 2:
		return "UK";

	case 3:
		return "Germany";

	case 4:
		return "Italy";

	case 5:
		return "South Africa";

	case 6:
		return "Singapore";
	}
	return "";
}

void Graph::create()  // Function to create an undirected graph
{
	int f=0;
	cout<<"\nEnter the number of the countries where you want to lease the phone lines : ";
	cin>>v;
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			g[i][j]=0;
	int k=0;
	for(int i=0;i<v;i++)
	{
		for(int j=i+1;j<v;j++)
		{
			cout<<"\nDo the office in "<<stringOf(i)<<" connected with that in "<<stringOf(j)<<" ? ( Yes:1 , No:0 ) : ";
			cin>>f;
			if(f)
			{
				cout<<"\nEnter a cost charged in K Rs.: ";
				cin>>g[i][j];
				g[j][i] = g[i][j]; // updating symmetric elements
				ed[k].src = i;
				ed[k].dest = j;
				ed[k].wt = g[i][j];
				k++;
			}
		}
	}
	e=k;
}

void Graph::displayGraph()
{
	cout<<"| Source |  Destination  | cost (K Rs.) |"<<endl;
	for(int i=0;i<e;i++)
	{
		cout<<setw(8);
		cout<<stringOf(ed[i].src)<<setw(15)<<stringOf(ed[i].dest)<<setw(10)<<ed[i].wt<<endl;
	}
	cout<<endl;
}

void Graph::displayMST()
{
	cout<<"\nThe spanning tree from the given graph is: "<<endl;

	cout<<"\n| Source | Destination | cost (K Rs.) |"<<endl;

	for(int i=0;i<v-1;i++)
	{
		cout<<setw(8);
		cout<<stringOf(T[i].src)<<setw(12)<<stringOf(T[i].dest)<<setw(10)<<T[i].wt<<endl;
	}

	cout<<"\nThe total minimum cost the business house has to pay is : "<<1000*cost<<" Rs."<<endl;

}

int getMin(int key[],bool visited[],int n) // Function will return vertex having minimum key value
{
	int vertex;

	int min = MAX_INT;
	for(int i=1;i<n;i++)
	{
		if(!visited[i] && min>key[i])
		{
			min = key[i];
			vertex = i;
		}
	}
	return vertex;
}
void Graph::prims() // Algorithm to construct the minimum cost spanning tree
{
	bool visited[v]; // Array to maintain visit flag
	int par[v];  // Parent array will keep track of included vertices on MST
	
	int key[v]; // will contain updated costs of the vertices

	for(int i=0;i<v;i++)
	{
		key[i] = MAX_INT;
		visited[i] = 0;
		par[i] = -1;
	}

	visited[0] = 1;
	key[0] = 0;

	for(int count=0;count<v;count++)
	{
		int u = getMin(key,visited,v); // To get the vertex having minimum key value
		visited[u] = 1;  // setting the visit flag one for the vertex included in MST
		for(int j=0;j<v;j++)
		{
			if(!visited[j])  // Updating the key values of un-visited adjacent vertices to u
				if(g[u][j]<key[j] && g[u][j])
				{
					key[j] = g[u][j];
					par[j] = u;
				}
		}
	}

	createMST(par); // creating MST from the parent array 
}

void Graph::createMST(int par[])
{
	int k=0;
	for(int i=1;i<v;i++)
	{
		T[k].src = par[i];
		T[k].dest = i;
		T[k].wt = g[i][par[i]];
		cost+=T[k].wt;
		k++;
	}
}

/*
 * Graph.cpp
 *
 *  Created on: 20-Mar-2020
 *      Author: abhishek
 */

#include "Graph.h"
#include <iostream>
#include <iomanip>
#include <string>
#define MAX_INT 100000

using namespace std;


Graph::Graph() {
	// TODO Auto-generated constructor stub
	 v = e = 0;
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

string stringOf(int num)
{
	switch(num)
	{
	case 0:
		return "Mumbai";

	case 1:
		return "Pune";

	case 2:
		return "Chennai";

	case 3:
		return "Bengaluru";

	case 4:
		return "Hyderabad";

	case 5:
		return "Kolkata";

	case 6:
		return "Delhi";
	}
	return "";
}

void Graph::create()
{
	int f=0;
	cout<<"\nEnter the number of cities you want to visit : ";
	cin>>v;
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			g[i][j]=0;
	int k=0;
	for(int i=0;i<v;i++)
	{
		cout<<"------------------------------------------------------------------"<<endl;
		for(int j=0;j<v;j++)
		{

			if(i!=j && !g[i][j])
			{
				cout<<"\nDo "<<stringOf(i)<<" has direct route to "<<stringOf(j)<<" ? ( Yes:1 , No:0 ) : ";
				cin>>f;
				if(f)
				{
					cout<<"\nEnter the distance in Kilometres : ";
					cin>>g[i][j];
					g[j][i] = g[i][j];
					k++;
				}
			}
		}
	}
	e=k;
	cout<<"------------------------------------------------------------------"<<endl;

}

void Graph::display()
{
	cout<<setw(18);

	for(int i=0;i<v;i++)
	{
		cout<<stringOf(i)<<setw(9);
	}
	cout<<endl;
	for(int i=0;i<v;i++)
	{
		cout<<stringOf(i)<<setw(9);
		for(int j=0;j<v;j++)
		{
			cout<<g[i][j]<<setw(9);
		}
		cout<<endl;
	}
}
int minDistance(int dist[],bool S[],int v)
{
	int min = MAX_INT;
	int min_index=0;
	for(int i=0;i<v;i++)
	{
		if(!S[i] && dist[i]<min)
		{
			min = dist[i];
			min_index = i;
		}
	}

	return min_index;
}

void Graph::dijkstra()
{
	int src;

	cout<<"\nEnter the source vertex number: ";
	cin>>src;

	int dist[v],par[v];
	bool S[v];

	for(int i=0;i<v;i++)
	{
		dist[i]=MAX_INT;
		S[i] = 0;
		par[i]=-1;
	}
	dist[src] = 0;

	for(int i=0;i<v;i++)
	{
		int u = minDistance(dist,S,v);
		S[u]=1;
		for(int j=0;j<v;j++)
		{
			if(g[u][j] && !S[j] && dist[u]!=MAX_INT)
			{
				if(dist[j]>(dist[u]+g[u][j]))
				{
					dist[j] = dist[u] + g[u][j];
					par[j] = u;
				}

			}
		}
	}
	displaySolution(dist,par,src);
}

void Graph::displaySolution(int dist[],int par[],int src)
{
	int p;
	cout<<"\nThe starting point of the journey is :"<<stringOf(src)<<" :"<<endl;
	cout<<endl;
	cout<<"\n\n------------------------------------------------------------------"<<endl;
	cout<<setw(5)<<"Destination"<<setw(12)<<" Min Distance(KM)"<<setw(12)<<" Optimal Route ( by road )"<<endl;
	cout<<"------------------------------------------------------------------"<<endl;
	for(int i=0;i<v;i++)
	{
		cout<<setw(3)<<stringOf(i)<<setw(12)<<dist[i]<<setw(15);
		cout<<stringOf(i)<<" <- ";
		p = par[i];
		while(p!=-1)
		{
			cout<<stringOf(p)<<"<-";
			p = par[p];
		}
		cout<<endl;
	}
	cout<<"------------------------------------------------------------------"<<endl;

}



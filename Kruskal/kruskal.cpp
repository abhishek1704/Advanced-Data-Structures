
#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 50

class Graph
{
	int g[MAX][MAX],v,e,cost;
	struct GraphStruct
	{
		int src,dest,wt;
	};
	struct GraphStruct gh[MAX],T[MAX];
public:
	void create();
	void kruskal();
	void displayGraph();
	void displayMST();
};

int find(int edges[],int i) // Function to find the set of the given vertex
{
	if (edges[i] == -1)
	        return i;
	    return find(edges, edges[i]);
}

void Graph::create()  // Function to create an undirected graph
{
	int f=0;
	cout<<"\nEnter the number of the vertex for the graph: ";
	cin>>v;
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			g[i][j]=0;
	int k=0;
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{

			if(i!=j && !g[i][j])
			{
				cout<<"\nDo "<<i+1<<" has edge with "<<j+1<<" ? ( Yes:1 , No:0 ) : ";
				cin>>f;
				if(f)
				{
					cout<<"\nEnter a weight: ";
					cin>>g[i][j];
					g[j][i] = g[i][j];
					gh[k].src = i+1;
					gh[k].dest = j+1;
					gh[k].wt = g[i][j];
					k++;
				}
			}
		}
	}
	e=k;

}

void Graph::displayGraph()
{
	cout<<"| Source | Destination | Weight |"<<endl;
	for(int i=0;i<e;i++)
	{
		cout<<setw(8);
		cout<<gh[i].src<<setw(12)<<gh[i].dest<<setw(12)<<gh[i].wt<<endl;
	}
	cout<<endl;
}

void Graph::displayMST()
{
	cout<<"\nThe spanning tree from the given graph is: "<<endl;
	cout<<"\n| Source | Destination | Weight |"<<endl;
	for(int i=0;i<v-1;i++)
	{
		cout<<setw(8);
		cout<<T[i].src<<setw(12)<<T[i].dest<<setw(12)<<T[i].wt<<endl;
	}

	cout<<"\nThe cost of the MST is : "<<cost<<endl;

}
void Graph::kruskal() // Algorithm to construct the minimum cost spanning tree
{
	int edges[v+1];
	for(int i=0;i<v+1;i++)
		edges[i]=-1;

	GraphStruct temp;
	int j=0;

	for(int i=1;i<e;i++)  // Sorting the given graph matrix
	{
		temp = gh[i];
		for(j=i-1;(j>=0 && (temp.wt>gh[j].wt));j--)
			gh[j+1] = gh[j];
		gh[j+1] = temp;
	}

	int k=0;cost=0;
	
	// Find and union algorithm
	
	for(int i=e-1;i>=0;i--)
	{
		int x = find(edges, gh[i].src);   // finding the set number of the two vertices of an edge
		int y = find(edges, gh[i].dest);

		if (x != y)		// Adding the edge into the spanning tree if it is not creating any cycle
		{
		   T[k].dest = gh[i].dest;
		   T[k].src = gh[i].src;
		   T[k].wt = gh[i].wt;
		   cost+=gh[i].wt;
		   edges[x] = y; 		// union of two sets
		   k++;
		}
	}
}

int main() {

	int ch;
	Graph g;

	do
	{
		cout<<"\n\nMain Menu:\n\n1. Create a graph\n2. Display Graph c\n3. Create MST from the graph\n4. Display the MST\n5. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			g.create();;
			break;

		case 2:
			g.displayGraph();
			break;

		case 3:
			g.kruskal();
			break;

		case 4:
			g.displayMST();
			break;

		case 5:
			break;
		}
		if(ch==5)
			break;
	}while(1);

	return 0;
}

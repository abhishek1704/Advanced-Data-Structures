
#include <iostream>
#include "Graph.h"
using namespace std;

class facebook
{
public:
	void createUser(Graph&);
	void display();
	void createFriends(Graph&);
	void displayFriends(Graph&);
	void dfs(Graph&);
	void maxComm(Graph&);
	void bfs(Graph&);
};

void facebook::createUser(Graph& g)
{
	int n;
	for(int i=0;i<4;i++)
		g.create(i+1);
}

void facebook::createFriends(Graph& g)
{
	g.createLink();
}

void facebook::dfs(Graph& g)
{
	g.depthFirst();
}


void facebook::bfs(Graph& g)
{
	g.maxFriends();
}


void facebook::maxComm(Graph& g)
{
	g.breadthFirst();
}

int main() {
	int ch;

	facebook f;
	Graph g;

	g.display();


	do
	{
		cout<<"\n\nMain Menu:\n\n1. Create a graph\n2. Display Graph \n3. Check birthdays in month \n4. Max friends\n5. Max comments\n6. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			f.createUser(g);
			f.createFriends(g);
			break;

		case 2:
			g.display();
			break;

		case 3:
			f.dfs(g);
			break;

		case 4:
			f.bfs(g);
			break;

		case 5:
			f.maxComm(g);
			break;

		case 6:
			break;
		}
		if(ch==6)
			break;
	}while(1);


}


#include <iostream>
#include "Graph.h"
using namespace std;

int main() {

	int ch;
	Graph g;

	do
	{
		cout<<"\n\nMain Menu:\n\n1. Create a city network ( Graph ) \n2. Display Graph \n3. Evaluate shortest path\n4. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			g.create();
			break;

		case 2:
			cout<<"\nAdjacency matrix representation: "<<endl;
			g.display();
			break;

		case 3:
			g.dijkstra();
			break;

		case 4:
			break;
		}
		if(ch==4)
			break;
	}while(1);

	return 0;
}

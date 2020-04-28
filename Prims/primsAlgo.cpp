
#include <iostream>
#include "Graph.h"
using namespace std;


int main() {

	int ch;
	Graph g;

	do
	{
		cout<<"\n\nMain Menu:\n\n1. Create phone network\n2. Display network\n3. Create MST from the graph\n4. Display the MST\n5. Exit"<<endl;
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
			g.prims();
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

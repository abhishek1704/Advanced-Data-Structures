//============================================================================
// Name        : newAss2.cpp
// Author      : Abhishek
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Queue.h"
#include "Queue.cpp"
using namespace std; 

int main() {
	
	Queue q;
	int ch,n;
	
	do
	{
		cout<<"\nMain Menu:\n1. Get patient data\n2. Display\n3. Serve a patient\n4. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"Enter number of patients to be served: ";
				cin>>n;
				
				for(int i=0;i<n;i++)
					q.enqueue();
				break;
			
			case 2:
				q.display();
				break;
				
			case 3:
				q.dequeue();
				break;
			
			case 4: 
				break;	

			default:
				cout<<"You have entered a wrong choice !!"<<endl;
		}
		if(ch==4)
			break;
	
	}while(1);		
					
	return 0;
}

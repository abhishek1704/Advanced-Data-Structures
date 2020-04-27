

#include "Student.h"
#include <iostream>
#include <string>
using namespace std;


int main() {

	Student st;
	string tel;

	int ch,n;
	bool f;

	do
	{
		cout<<"\n\nMain Menu:\n\n1. Create table\n2. Display record \n3. Insert multiple records \n4. Insert single record\n5. Search\n6. Delete\n7. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			st.createTable();
			break;

		case 2:
			st.display();
			break;

		case 3:
			cout<<"Enter the number of records you want to insert: ";
			cin>>n;
			for(int i=0;i<n;i++)
				st.insert();
			break;

		case 4:
			st.insert();
			break;

		case 5:
			cout<<"\nEnter a telephone number to search : ";
			cin>>tel;
			f = st.search(tel);
			if(f)
				cout<<"\nRecord found !"<<endl;
			else
				cout<<"\nRecord does not exist !"<<endl;
			break;

		case 6:
			cout<<"\nEnter a telephone number to delete : ";
			cin>>tel;
			st.delet(tel);
			break;

		case 7:
			break;

		default:
			cout<<"\nYou have entered a wrong choice !"<<endl;
			break;
		}
		if(ch==7)
			break;
	}while(1);

	return 0;
}

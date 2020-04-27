
#include "Student.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Student::Student() {

	stud = NULL;
	size = 0;
	isReplace = 0;
	// TODO Auto-generated constructor stub

}

Student::~Student() {
	// TODO Auto-generated destructor stub
}


void Student::createTable()
{

	cout<<"Enter the number of students : ";
	cin>>size;

	stud = new HashTable[size];
	for(int i=0;i<size;i++)
	{
		stud[i].name = "-1";
		stud[i].tel_no = "-1";
		stud[i].chain = -1;
		stud[i].flag = 0;
	}

	cout<<"\nEnter the implementation type\n0. Without replacement\n1. With replacement\n::";
	cin>>isReplace;
}

int Student::hashFunction(string key)
{
	int index = 0;
    stringstream obj(key);
    obj>>index;

	index %= size;
	return index;
}

void Student::insert()
{
	HashTable temp;

	cout<<"Enter the name of a student : ";
	cin>>temp.name;
	cout<<"Enter the telephone number of a student : ";
	cin>>temp.tel_no;
	temp.flag = 1;
	temp.chain = -1;
	if(isReplace)
		insertWithReplacement(temp);
	else
		insertWithoutReplacement(temp);
}

void Student::insertWithReplacement(HashTable h)
{
	int index = hashFunction(h.tel_no);
	int i=0;
	cout<<index<<endl;
	if(stud[index].flag==0)// if the index location is empty, insert and return
	{
		stud[index] = h;
		return;
	}
	else
	{
		if(index == hashFunction(stud[index].tel_no)) //  Simple Chaining with linear probing
		{
			int count = 0;
			i = index;
			while(count<size && stud[i].chain!=-1)
			{
				index = stud[i].chain;
				i = index;
				count++;
			}
			while(count<size && stud[i].flag != 0)
			{
				i = (i + 1) % size;
				count++;
			}

			if(count==size)
			{
				cout<<"Table is full, key cannot be inserted !"<<endl;
				return;
			}

			stud[i] = h;
			stud[index].chain = i;
		}
		else // Replacement when the element present at generated index belong to some other index
		{
			int count = 0;
			i = index;
			while((stud[i].flag!=0) && count<size) // i will give the empty location if table is not full
			{
				i = (i + 1) % size;
				count++;
			}

			if(count==size)
			{
				cout<<"Table is full, key cannot be inserted !"<<endl;
				return;
			}

			int j = hashFunction(stud[index].tel_no);	// expected location of entry present at generated index

			while(stud[j].chain != index)	// traverse through the chain of element at generated index upto index
				j = stud[j].chain;

			stud[j].chain = stud[index].chain;

			while(stud[j].chain != -1) // Get the last location of the chain
				j = stud[j].chain;

			stud[i] = stud[index];
			stud[i].flag = 1;
			stud[i].chain = -1; // i will be the last location of chain
			stud[j].chain = i;

			stud[index] = h;	// insert new where it actually belongs
			stud[index].chain = -1;
		}
	}

}

void Student::insertWithoutReplacement(HashTable h)
{

	int index = hashFunction(h.tel_no);

	cout<<index<<endl;
	if(stud[index].flag==0)// if the index location is empty, insert and return
	{
		stud[index] = h;
		return;
	}
	else
	{
		int count = 0, j = index;
		while(stud[j].flag != 0 && count < size)	 // find the empty location to insert
		{
			if(hashFunction(stud[index].tel_no) == index) // if chain is encountered ,break.
				break;
			j = (j + 1) % size;
			count++;
		}
		if(count == size)
		{
			cout<<"Table is full, key cannot be inserted !"<<endl;
			return;
		}

		while(stud[j].chain != -1) // traverse till last element of chain
			j = stud[j].chain;

		index = j;
		while(stud[index].flag != 0 && count < size)	// linear probing after the end of the chain if present
		{
			index = (index + 1) % size;
			count++;
		}
		if(count == size)
		{
			cout<<"Table is full, key cannot be inserted !"<<endl;
			return;
		}
		stud[index] = h;
		stud[index].flag = true;
		if(j != index)
			stud[j].chain = index;
	}
}

bool Student::search(string key)
{
	int index = hashFunction(key);
	int count = 0,i;
	i=index;
	while(stud[i].tel_no != key && stud[i].chain!=-1)
	{
		index = stud[i].chain;
		i = index;
	}

	if(stud[i].tel_no==key)
		return 1;
	else
		return 0;
}

void Student::delet(string key)
{
	if(search(key))		// if entry exists
	{
		int index = hashFunction(key), i = index;

		while(stud[i].tel_no != key && stud[i].chain != -1)	// traverse through the chain
			i = stud[i].chain;


		if(index != i)	// if chain is present
		{
			while(stud[index].chain != i)	// traverse the chain upto the index of the key
				index = stud[i].chain;

			stud[index].chain = stud[i].chain;	// update chain
			stud[i] = {"-1","-1",-1,0};	// delete the key by overwriting
		}
		else // if chain is not present, then simply delete the index location
			stud[i] = {"-1","-1",-1,0};

		cout<<"\nRecord deleted successfully !"<<endl;

	}
	else
		cout << "\nRecord not found ! Cannot be deleted !.\n";
}

void Student::display()
{

	cout << "\nBucket Number\t\tName\t\tMobile Number\t\tChain\n";
	for(int i = 0;i < size;i++)
	{
		cout << setw(7) << i << setw(20) << stud[i].name << setw(20) << stud[i].tel_no << setw(20) << stud[i].chain << endl;
	}
}

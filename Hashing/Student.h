
#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
using namespace std;

typedef struct HashTable
{
	string name;
	string tel_no;
	int chain,flag;

}stud;

class Student {

	HashTable *stud;
	int size;
	bool isReplace;

public:
	Student();
	void createTable();
	int hashFunction(string);
	void insertWithoutReplacement(HashTable);
	void insertWithReplacement(HashTable);
	void insert();
	bool search(string);
	void delet(string);
	void display();
	virtual ~Student();
};

#endif /* STUDENT_H_ */

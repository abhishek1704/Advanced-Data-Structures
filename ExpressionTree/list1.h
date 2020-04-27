/*
 * list.h
 *
 *  Created on: 18-Dec-2019
 *      Author: dsflh-9
 */

#ifndef LIST_H_
#define LIST_H_

using namespace std;

template<class T>
class list1;

template<class T>
class node
{
	public:
		T data;
		node<T> *next;

};

template<class M>
class list1 {
	node<M> *head,*last;
	public:
		list1();
		node<M>* insert(node<M>*,M);
		node<M>* delet(node<M>*);
		int empty(node<M>*);
		void display(node<M>*);
		M dispHead(node<M>*);
		virtual ~list1();
};

#endif /* LIST_H_ */

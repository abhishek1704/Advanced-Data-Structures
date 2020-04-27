/*
 * Stack1.h
 *
 *  Created on: 18-Dec-2019
 *      Author: dsflh-9
 */

#ifndef STACK1_H_
#define STACK1_H_
#include "list.h"

template<class T>
class Stack1 {
	node<T> *top;
public:
	Stack1();
	void push(T);
	void pop();
	bool isEmpty();
	T isTop();
	void display();
	virtual ~Stack1();
};

#endif /* STACK1_H_ */

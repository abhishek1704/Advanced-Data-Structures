/*
 * Stack1.cpp
 *
 *  Created on: 18-Dec-2019
 *      Author: dsflh-9
 */

#include "stack1.h"
#include <iostream>
#include "list1.cpp"

template<class M>
Stack1<M>::Stack1() {
	top = NULL;
	// TODO Auto-generated constructor stub

}

template<class M>
Stack1<M>::~Stack1() {
	// TODO Auto-generated destructor stub
}

template<class M>
void Stack1<M>::push(M value)
{
	list1<M> l;
	top = l.insert(top,value);
}

template<class M>
M Stack1<M>::pop()
{
	list1<M> l;
	top = l.delet(top);

}

template<class M>
bool Stack1<M>::isEmpty()
{
	list1<M> l;
	if(l.empty(top))
		return 1;
	else
		return 0;

}

template<class M>
M Stack1<M>::isTop()
{
	list1<M> l;
	M t = l.dispHead(top);
	return t;
}

template<class M>
void Stack1<M>::display()
{
	list1<M> l;
	l.display(top);
}

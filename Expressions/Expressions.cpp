#include <iostream>
#include "stack1.h"
#include <cstring>
#include <string>
#include "Stack1.cpp"
#include <cmath>
using namespace std;

class expr
{
	string s,result;

	public:
		expr()
		{
			s.append(" ");
			s.append(" ");
		}
		void get();
		void inToPost(Stack1<char> st);
		void inToPre(Stack1<char> st);
		int evalPost(Stack1<int> st,int flag);
		int evalPre(Stack1<int> st,int flag);
		bool isPostfix();
		bool isPrefix();
		int op_fn(char c,int b,int a);
		int prec(char);
		char asso(char);
		void display();
};

int expr::prec(char ch) // will return equivalent precedence
{
	switch(ch)
	{
		case '+':
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 3;
		case '^':
			return 4;
	}
}

char expr::asso(char a) // will return equilvalent associativity
{
	switch(a)
	{
		case '+':
		case '-':
		case '*':
		case '/':
			return 'L';
		case '^':
			return 'R';
	}
}

int expr::op_fn(char c,int b,int a)
{
	switch(c)
	{
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		case '^':
			return pow(a,b);
	}
}

bool expr::isPostfix() // validation for postfix expression
{
	int l = s.length();
	if(isdigit(s[0]) && isdigit(s[1]) && !isdigit(s[l-1]))
		return 1;
	else
		return 0;
}

bool expr::isPrefix() // validation for prefix expression
{
	int l = s.length();
	if(isdigit(s[l-1]) && isdigit(s[l-2]) && !isdigit(s[0]))
		return 1;
	else
		return 0;
}

void expr::get()
{
	cout<<"Enter an expression: "<<endl;
	cin>>s;
}

int expr::evalPost(Stack1<int> st,int flag) // Evaluation of postfix expression
{
	for(int i=0;i<s.length();i++)
	{

		if(isdigit(s[i])) // if digit, push it into the stack
		{
			int temp = (int)s[i];
			temp-=48;
			st.push(temp);
		}
		else // otherwise pop two values and evaluate them and again push them onto the stack
		{
			int temp = st.isTop();
			st.pop();
			int temp1 = st.isTop();
			st.pop();
			if(flag)
			{
				temp = op_fn(s[i],temp,temp1);
				st.push(temp);
			}
			else
			{
				temp = op_fn(s[i],temp1,temp);
				st.push(temp);
			}
		}
	}
	return st.isTop(); // result
}

int expr::evalPre(Stack1<int> st,int flag) // evaluation of prefix expression using 
					   // function for evaluation of posfix expression
{
	int l = s.length();
	for(int i=0;i<l/2;i++)
	{
		char temp = s[i];
		s[i] = s[l-i-1];
		s[l-i-1] = temp;
	}
	int val = evalPost(st,flag);
	return val;
}

void expr::inToPost(Stack1<char> st) // infix to postfix conversion
{
	st.push('(');
	s.push_back(')');
	for(int i=0;i<s.length();i++)
	{

		if(int(s[i])>=65 && int(s[i])<=90)
		{
			result.push_back(s[i]);
		}
		else if(s[i]=='(')
		{
			st.push('(');
		}
		else if(s[i]==')')
		{
			while((st.isTop())!='(')
			{
				result.push_back(st.isTop());
				st.pop();
			}
			st.pop();
		}
		else
		{
			if(st.isTop()=='(')
				st.push(s[i]);
			else if(prec(s[i])>prec(st.isTop()))
			{
				st.push(s[i]);
			}
			else if(prec(s[i])==prec(st.isTop()) && asso(s[i])=='R')
			{
				st.push(s[i]);
			}
			else
			{
				result.push_back(st.isTop());
				st.pop();
				st.push(s[i]);
			}
		}
	}
}

void expr::inToPre(Stack1<char> st) // infix to prefix conversion using function for infix to postfix 
{
	int l = s.length();
	for(int i=0;i<l/2;i++)
	{
		char temp = s[i];
		s[i] = s[l-i-1];
		s[l-i-1] = temp;
	}
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(')
			s[i] = ')';
		else if(s[i]==')')
			s[i] = '(';
	}


	inToPost(st);
	l = result.length();
	for(int i=0;i<l/2;i++)
	{
		char temp = result[i];
		result[i] = result[l-i-1];
		result[l-i-1] = temp;
	}
}

void expr::display()
{
	cout<<result<<endl;
	result.clear();
}

int main()
{
	int ch,val;
	Stack1<char> st;
	Stack1<int> st1;
	expr e;

	do
	{
		cout<<"\n\n__Main Menu__\n\n1. Infix to Postfix\n2. Infix to Prefix\n3. Eval Postfix\n4. Eval Prefix\n5. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			e.get();
			e.inToPost(st);
			cout<<"The Post fix expresssion is: "<<endl;
			e.display();
			break;

		case 2:
			e.get();
			e.inToPre(st);
			cout<<"The Prefix expresssion is: "<<endl;
			e.display();
			break;

		case 3:
			e.get();
			if(e.isPostfix())
			{
				val = e.evalPost(st1,1);
				cout<<"\nThe result of the expression is: ";
				cout<<val;
			}
			else
				cout<<"\nThe expression is not postfix !!"<<endl;
			break;

		case 4:
			e.get();
			if(e.isPrefix())
			{
				val = e.evalPre(st1,0);
				cout<<"The result of the expression is: ";
				cout<<val;
			}
			else
				cout<<"\nThe expression is not prefix !!"<<endl;
			break;

		case 5:
			break;

		}
		if(ch==5)
			break;
	}while(1);

	return 0;

}



#include <iostream>
#include <string>
#include "stack1.h"
#include "stack1.cpp"
using namespace std;

class Tree;

class node1
{
	char ch;
	node1 *left,*right;
public:
	friend class ExpTree;
};

class ExpTree
{
	node1 *root;
public:
	ExpTree();
	node1* createExpTree();
	void create();
	void inorder(node1 *p);
	void inorderNonRec(node1 *p);
	void postorder(node1 *p);
	void postorderNonRec();
	void preorder(node1 *p);
	void preorderNonRec(node1 *p);
	void display();
	int depth(node1*);
	void height();
};

ExpTree::ExpTree() // Constructor
{
	root = NULL;
}

void ExpTree::create()
{
	root = createExpTree();
}

node1* ExpTree::createExpTree() // Creation of an expression tree using stack
{
	string s;
	Stack1<node1*> st;
	node1 *p,*temp1,*temp2;

	cout<<"Enter any post fix expression: "<<endl;
	cin>>s;

	for(int i=0;i<s.length();i++)
	{
		if(int(s[i])>=65 && int(s[i])<=90) // if operator, push onto the stack 
		{
			p = new node1;
			p->left = p->right = NULL;
			p->ch = s[i];
			st.push(p);
		}
		else  // otherwise, pop two nodes from the stack and set them to the left and right of the new node
		{     // and push entire subtree onto the stack
			p = new node1;
			p->left = p->right = NULL;
			p->ch = s[i];
			temp1 = st.isTop();
			st.pop();
			p->right = temp1;
			temp2 = st.isTop();
			st.pop();
			p->left = temp2;
			st.push(p);
		}
	}

	temp1 = st.isTop();
	st.pop();
	return temp1; // return root of the tree created
}

void ExpTree::inorder(node1 *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<p->ch<<" ";
		inorder(p->right);
	}

	return;
}

void ExpTree::preorder(node1 *p)
{
	if(p!=NULL)
	{
		cout<<p->ch<<" ";
		preorder(p->left);
		preorder(p->right);
	}

	return;
}

void ExpTree::postorder(node1 *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<p->ch<<" ";
	}
	return;
}

void ExpTree::inorderNonRec(node1 *p)
{
	Stack1<node1*> st;

    while (p != NULL || st.isEmpty() == 0) 
    { 
        while (p !=  NULL) 
        { 
            st.push(p); 
            p = p->left; 
        } 
  
        p = st.isTop(); 
        st.pop(); 
  
        cout << p->ch << " "; 
        p = p->right;   
    } 
}

void ExpTree::preorderNonRec(node1 *p)
{
	Stack1<node1*> st;

	while(p!=NULL)
	{
		cout<<p->ch<<" ";
		if(p->right!=NULL)
		{
			st.push(p->right);
		}
		if(p->left!=NULL)
		{
			p = p->left;
		}
		else
		{
			p = st.isTop();
			st.pop();
		}
	}

}

void ExpTree::postorderNonRec()
{
    if (root == NULL) 
        return; 
 
	Stack1<node1*> st;    
    do
    { 
        while (root) 
        { 
        	if (root->right) 
                st.push(root->right);
            st.push(root);   

            root = root->left; 
        }   

        root = st.isTop();
        st.pop(); 
  
        if (root->right && st.isTop() == root->right) 
        { 
            st.pop();  
            st.push(root); 
            root = root->right;
        } 
        else
        { 
            cout<<root->ch<<" "; 
            root = NULL; 
        } 
    } while (!st.isEmpty()); 	
}

void ExpTree::display()
{
	int ch;

	do
	{
		cout<<"\n\nMenu :\n1. Display root\n2. Inorder\n3. Postorder\n4. Pre order\n5. Exit\n"<<endl;
		cout<<"Choose display option: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"The data of the root is: "<<endl;
			cout<<root->ch;
			break;

		case 2:
			cout<<"\nThe in order traversal for tree : "<<endl;
			inorder(root);cout<<endl;
			inorderNonRec(root);
			break;

		case 3:
			cout<<"\nThe post order traversal for tree : "<<endl;
			postorder(root);cout<<endl;
			postorderNonRec();
			break;

		case 4:
			cout<<"\nThe pre order traversal for tree : "<<endl;
			preorder(root);cout<<endl;
			preorderNonRec(root);
			break;

		case 5:
			break;
		}
		if(ch==4)
			break;

	}while(1);
}

int main() {

	ExpTree t;
	int ch;
	
	do
	{
		cout<<"\nMain Menu\n1. Create\n2. Display\n3. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				t.create();
				break;
			
			case 2:
				t.display();
				break;
			
			case 3:
				break;
				
			default:
				cout<<"You have entered a wrong choice !"<<endl;
		}
		if(ch==3)
			break;
	}while(1);
	
	return 0;
}


//AB^C*C-DA/EE+/+
//AB^C*G-DF/EH+/+

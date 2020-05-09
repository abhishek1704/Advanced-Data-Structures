
#include <iostream>
#define MAX 50
using namespace std;

class BST;

class node
{
	node *left,*right;
	int data;

public:
	friend class BST;
};

class BST
{
	node *root;
	node *q[MAX];
	int f,r;
public:
	BST();
	void createBST();
	void insert();
	void display();
	void inorder(node*);
	void search(int,node**,node**);
	void delet(int);
	BST createMirror();
	node* mirrorImg(node*);
	void displayLevelWise();
};

BST::BST() // constructor
{
	root = NULL;
	f = r = -1;
}

void BST::createBST() 
{
	int n;
	cout<<"Enter the number of nodes you want to create: ";
	cin>>n;

	for(int i=0;i<n;i++)
		insert();

}
void BST::insert() // Non-recursive function to insert a node in BST
{
	node *p = root;
	int data;
	if(root==NULL)
	{
		p = new node;
		p->left=p->right=NULL;
		cout<<"Enter data for the root: ";
		cin>>p->data;
		root = p;
		return;
	}

	cout<<"Enter a data: ";
	cin>>data;
	do
	{
		if(data<=p->data)
		{
			if(p->left==NULL)
			{
				p->left=new node;
				(p->left)->left=(p->left)->right=NULL;
				(p->left)->data=data;
				return;
			}
			else
				p = p->left;
		}
		else if(data>p->data)
		{

			if(p->right==NULL)
			{
				p->right=new node;
				(p->right)->left=(p->right)->right=NULL;
				(p->right)->data=data;
				return;
			}
			else
				p = p->right;
		}

	}while(1);
}

void BST::display()
{
	if(root==NULL)
		cout<<"The tree is empty !"<<endl;
	else
		inorder(root);
	cout<<endl;
}

void BST::inorder(node *p) // Recursive inorder traversal
{
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<p->data<<" ";
		inorder(p->right);
	}

	return;
}

void BST::search(int key,node **loc,node **par) // to search a node in BST
{
	if(root==NULL)
	{
		cout<<"The tree is empty !!"<<endl;
		return;
	}
	node *temp=root;
	while(temp!=NULL)
	{
		if(key<temp->data)
		{
			*par = temp;
			temp = temp->left;
		}
		else if(key>temp->data)
		{
			*par = temp;
			temp = temp->right;
		}
		else
		{
			*loc = temp;
			cout<<"Data found !!"<<endl;
			return;
		}
	}

	if(temp==NULL)
	{
		cout<<"Data not found !!"<<endl;
		loc = NULL;
	}
}

void BST::delet(int key) // function to delete node from BST
{
	node *temp,*loc,*par;

	if(root==NULL) // Check if tree is empty
	{
		cout<<"The tree is empty !!";
		return;
	}

	if(root->data==key && root->left==NULL && root->right==NULL) // To delete the root if key is equal to the root
	{
		temp = root;
		root = NULL;
		delete temp;
		cout<<"Now tree is empty !!"<<endl;
		return;
	}

	search(key,&loc,&par); // Search a key and get the location of node and its parent


	if(loc==NULL) // Check if key not found
	{
		cout<<"The key not found !"<<endl;
		return;
	}

	if(loc->right==NULL && loc->left==NULL) // To delete the leaf node
	{
		if(loc==par->left)
			par->left = NULL;
		else
			par->right = NULL;

		temp = loc;
		delete temp;
		return;
	}

	if(loc->left!=NULL && loc->right==NULL) 	// To delete the node having single child
	{
		if(par->left==loc)
			par->left=loc->left;
		else
			par->right = loc->left;

		temp = loc;
		delete temp;
		return;
	}
	else if(loc->left==NULL && loc->right!=NULL)
	{
		if(par->left==loc)
			par->left = loc->right;
		else
			par->left = loc->right;

		temp = loc;
		delete temp;
		return;
	}

	if(loc->right!=NULL && loc->left!=NULL) // To delete the node having two children
	{
		int temp1 = loc->data;
		loc->data = (loc->right)->data;
		(loc->right)->data = temp1;


		loc->right = NULL;
		temp = loc->right;
		delete temp;
	}
}

BST BST::createMirror()
{
	BST tm;
	tm.root = mirrorImg(root);
	return tm;
}

node* BST::mirrorImg(node* p) // Recursive function to create a mirror image of BST
{

	if(p==NULL)
		return p;

	node *temp = new node;
	temp->data = p->data;
	temp->left = mirrorImg(p->right);
	temp->right = mirrorImg(p->left);

	return temp;
}

void BST::displayLevelWise() // Levelwise traversal of BST using queue ( BFS )
{
	node* temp;
	if(root==NULL)
	{
		cout<<"Tree is empty !"<<endl;
		return;
	}

	f++;r++;
	q[r] = root;

	while(r!=f-1)
	{
		temp = q[f];
		f++;
		cout<<temp->data<<" ";
		if(temp->left)
		{
			r++;
			q[r] = temp->left;
		}
		if(temp->right)
		{
			r++;
			q[r] = temp->right;
		}
	}
}

int main() {

	BST t,tm;
	node *loc,*par;
	int key,ch;

	do
	{
		cout<<"\n\nMenu :\n1. Create\n2. Display tree (inorder)\n3. Insert"<<endl;
		cout<<"4. Display levelwise \n5. Search\n6. Delete\n7. Mirror image"<<endl;
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			t.createBST();
			break;

		case 2:
			cout<<"\nThe tree with inorder traversal is: "<<endl;
			t.display();
			break;

		case 3:
			t.insert();
			break;

		case 4:
			cout<<"\nThe levelwise traversal is: "<<endl;
			t.displayLevelWise();
			break;

		case 5:
			cout<<"\nEnter a key to search: ";
			cin>>key;
			t.search(key,&loc,&par);
			break;

		case 6:
			cout<<"\nEnter a key to delete: ";
			cin>>key;
			t.delet(key);
			break;

		case 7:
			tm = t.createMirror();
			cout<<"The inorder traversal for mirror image is:"<<endl;
			tm.display();
			break;

		case 8:
			break;

		default:
			cout<<"\nYou have entered a wrong choice !"<<endl;
			break;
		}
		if(ch==8)
			break;

	}while(1);

	return 0;
}


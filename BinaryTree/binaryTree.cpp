
#include <iostream>
using namespace std;

class Tree;

class node
{
	int data;
	node *left,*right;
public:
	friend class Tree;

};

class Tree
{
	node *root;
public:
	Tree();
	node* createBinTree();
	node* insertRec(node*);
	node* createCopy(node*);
	Tree copyTree();
	void insert();
	void displayLeaf(node*);
	void display();
	void inorder(node*);
	int depth(node*);
	void height();
};

Tree::Tree()
{
	root = NULL;
}

node* Tree::createBinTree()
{
	root = new node;
	root->left=root->right=NULL;

	cout<<"Enter data for the root: "<<endl;
	cin>>root->data;

	cout<<"Insert at left of the root :"<<endl;
	root->left = insertRec(root->left);
	cout<<"Insert at right of the root :"<<endl;
	root->right = insertRec(root->right);

	return root;
}

node* Tree::insertRec(node *p)
{
	int f;

	cout<<"\nPress 1 to insert (0:exit) :";
	cin>>f;

	if(!f)
		return p;

	p = new node;
	p->left=p->right=NULL;
	cout<<"Enter a data : ";
	cin>>p->data;

	cout<<"Insert at left of "<<p->data<<endl;
	p->left = insertRec(p->left);
	cout<<"Insert at right of "<<p->data<<endl;
	p->right = insertRec(p->right);

	return p;
}

void Tree::insert()
{
	node *p=root;
	int ch;


	if(root==NULL)
	{
		p = new node;
		p->left=p->right=NULL;
		cout<<"Enter data for the root: ";
		cin>>p->data;
		root = p;
		return;
	}

	do
	{
		cout<<"Where do you want to inert?\n1.Left of "<<p->data<<"\n2.Right of "<<p->data<<endl;
		cin>>ch;
		if(ch==1)
		{
			if(p->left==NULL)
			{
				p->left=new node;
				(p->left)->left=(p->left)->right=NULL;
				cout<<"Enter a data: ";
				cin>>(p->left)->data;
				return;
			}
			else
				p = p->left;
		}
		else if(ch==2)
		{

			if(p->right==NULL)
			{
				p->right=new node;
				(p->right)->left=(p->right)->right=NULL;
				cout<<"Enter a data: ";
				cin>>(p->right)->data;
				return;
			}
			else
				p = p->right;
		}

	}while(1);
}

Tree Tree::copyTree()
{
	Tree t;
	t.root = createCopy(root);
	return t;
}

node* Tree::createCopy(node *p)
{
	node *cpy;
	cpy = new node;
	cpy=p;

	if(p!=NULL)
	{
		cpy->left = createCopy(p->left);
		cpy->right = createCopy(p->right); 
	}

	return cpy;
}
void Tree::display()
{
	int ch;

	do
	{
		cout<<"\n\nMenu :\n1. Display root\n2. Display tree (inorder)\n3. Display Leaf Nodes\n4. Exit\n"<<endl;
		cout<<"Choose display option: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"The data of the root is: "<<endl;
			cout<<root->data;
			break;

		case 2:
			cout<<"\nThe in order traversal for tree : "<<endl;
			inorder(root);
			break;

		case 3:
			cout<<"The leaf nodes are: "<<endl;
			displayLeaf(root);
			break;

		case 4:
			break;
		}
		if(ch==4)
			break;

	}while(1);
}

void Tree::displayLeaf(node *p)
{
	int flag=0,flag2=0;
	if(p->left!=NULL)
	{
		displayLeaf(p->left);
		flag2=1;
	}
	else
	{
		cout<<p->data<<" ";
		flag=1;
	}
	if(p->right!=NULL)
	{
		displayLeaf(p->right);
	}
	else
	{
		if(!flag && !flag2)
			cout<<p->data<<" ";
	}
}

void Tree::inorder(node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<p->data<<" ";
		inorder(p->right);
	}	
}

int Tree::depth(node* t)
{
    if (t == NULL)
        return 0;
    else
    {
        int lDepth = depth(t->left);
        int rDepth = depth(t->right);
        return 1+max(lDepth,rDepth);
    }
}

void Tree::height()
{
	cout<<"The depth of the tree is : "<<depth(root)<<endl;
}

int main()
{
	Tree t,t1;
	int n,ch;

	do
	{
		cout<<"\n\nMain Menu:\n1. Create tree\n2. Insert node\n3. Display\n4. Depth of a tree\n5. Copy tree\n6. Exit"<<endl;
		cout<<"Enter your choice: "<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			t.createBinTree();
			break;

		case 2:
			t.insert();
			break;

		case 3:
			t.display();
			break;

		case 4:
			t.height();
			break;

		case 5:
			t1 = t.copyTree();
			t1.display();
			break;
		case 6:
			break;
			
		default:
			cout<<"You have entered a wrong choice !!"<<endl;
			break;
		}

		if(ch==6)
			break;
	}while(1);

	return 0;
}

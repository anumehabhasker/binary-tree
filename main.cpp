#include<iostream>


using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	
	node()
	{
		left=right=0;
	}
	node(int val)
	{
		data=val;
		left=0;
		right=0;
	}
	
};

class tree
{
	private:
	node* root;
	
	public:
	
	tree()
	{
		node();
	}
	
	tree(int root_val)
	{
		cout<<"\n in Tree constructor";
		root = new node;
		root->data=root_val;
		root->left=0;
		root->right=0;
		cout<<"\n leaving tree constructor";
	}
	void insertion(int node_val);
	void insert_node(int node_val,node* root);
	/*void delete_entry(int val)
	{
		delete_node(val, root);
	}
	void delete_node(int node_val, node* root); (http://www.algolist.net/Data_structures/Binary_search_tree/Removal)*/
	//void destroy_tree();
	void inorder()
	{
		inorder_printing(root);
	}
	void inorder_printing(node* root);
	void postorder()
	{
		postorder_printing(root);
	}
	void postorder_printing(node* root);	
	void preorder()
	{
		preorder_printing(root);
	}
	void preorder_printing(node* root);	
	//void count_nodes();	
	

};
void tree::insertion(int node_val)
{
	insert_node(node_val,root);
	cout<<"\n inserted the value \n";
}

void tree::insert_node(int node_val, node* root)
{
	//insert the value in the appropriate position
	if(root == 0)
	{
		root=new node;
		root->data=node_val;
		root->right=0;
		root->left=0;
	}
	else
	{
			
		if(root->data > node_val)
		{
			if(root->right == 0)
			{
				node *temp = new node(node_val);
				root->right=temp;
			}
			else
			{
				insert_node(node_val, root->right);
			}
		}

		else
		{
			if(root->left == 0)
			{
				node *temp = new node(node_val);
				root->left=temp;
			}
			else
			{
				insert_node(node_val,root->left);
			}
		}
	}
}//end of insert_node


void tree:: inorder_printing(node* root)
{
	if(root->right!=0)
		inorder_printing(root->right);
	cout<<root->data<<endl;
	if(root->left!=0)
		inorder_printing(root->left);
	
}


void tree:: preorder_printing(node* root)
{
	cout<<root->data<<endl;	
	
	if(root->right!=0)
		inorder_printing(root->right);
	
	if(root->left!=0)
		inorder_printing(root->left);
	
}

void tree:: postorder_printing(node* root)
{
	if(root->right!=0)
		inorder_printing(root->right);
	
	if(root->left!=0)
		inorder_printing(root->left);

	cout<<root->data<<endl;
	
}

/*
void tree:: delete_node(int node_val, node* root)
{
	if(root->data==node_val)
	{
		//case 1: root = leaf node
		if(root->left==0 && root->right==0)
		{
			node* temp=root;
			delete temp;
		}
		//case 2: root has only one child:
		else if(root->left==0||root->right==0)
		{
			
		}
		//case 3: root has both left and right children
	}
	
	else if(root->left!=0)
		if(root->left->data==node_val)
		{
			root->left=root->left;
			delete_node(node_val, root->left);
			
		}

	else if(root->right!=0)
		if(root->right->data == node_val)
		{
			delete_node(node_val,root->right);
			root->right=0;
		}				
}
*/
int main()
{
	cout<<"Welcome to Constructing a Binary Tree! Please enter root node value"<<endl;
	int x; cin>>x;
	cout<<"\n root value will be: "<<x<<endl;
	tree myTree(x);
	cout<<"\n tree created\n";
	myTree.insertion(5);
	myTree.insertion(6);
	myTree.insertion(2);
	myTree.inorder();

	return 0;
}

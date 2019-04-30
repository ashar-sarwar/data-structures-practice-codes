#include <stdlib.h>
#include <iostream>
using namespace std;

struct BT
{
	int value;
	BT *left;
	BT *right;
};
void insert(BT **root, int value)
{
	BT *temp;
	temp = (struct BT*)malloc(sizeof(BT));
	temp->value = value;
	temp->left = NULL;
	temp->right = NULL;

	if (*root == NULL)
	{
		*root = temp;
		return;
	}

	if (value > (*root)->value)
		insert(&((*root)->right), value);


	else if(value < (*root)->value)
		insert(&((*root)->left), value);


}

void search(BT *root, int value)
{
	if (root == NULL)
	{
		cout << "Value not found.\n";
		return;
	}
	if (root->value == value)
		{
			cout <<value<< " is present in the tree\n";
			return;
		}


	else {
        if (root->value >value)
	{

		search(root->left, value);
	}

	if (root->value < value)
	{

		search(root->right, value);
	}
}
}
BT* findMin(BT *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}


BT* deletee(BT *root, int value)
{

	if (root == NULL)
	{
		//cout << "Empty tree...\n";
		return root;
	}

	else if (root->value > value)
	{
	 root->left = deletee(root->left, value);

	}

	else if (root->value < value)
	{
	root->right =	deletee(root->right, value);
	}

	// Node deletion
	else
	{
		//case 1: Leaf Node
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			root=NULL;
			return root;
		}
		//case 2: one child
		else if(root->left==NULL)
		{
			struct BT* temp=root;
			root=root->right;
			delete temp;
			return root;
		}
		else if(root->right==NULL)
		{
			struct BT* temp=root;
			root=root->left;
			delete temp;
			return root;
		}
		//case 3: 2 child
else
		{
			struct BT *temp=findMin(root->right);
			root->value=temp->value;
			root->right=deletee(root->right,temp->value);
		}
	}

	return root;

}


void InorderTraversal(BT *root)
{
	if (root != NULL)
	{
		InorderTraversal(root->left);
		cout << root->value << endl;
		InorderTraversal(root->right);
	}
}

void PreorderTraversal(BT *root)
{
	if (root != NULL)
	{
		cout << root->value << endl;
		PreorderTraversal(root->left);
		PreorderTraversal(root->right);
	}
}

void PostOrderTraversal(BT *root)
{
	if (root != NULL)
	{
		PostOrderTraversal(root->left);
		PostOrderTraversal(root->right);
		cout << root->value << endl;
	}
}


int main()
{
	BT *root = NULL;
	insert(&root, 20);
	insert(&root, 15);
	insert(&root, 25);
	insert(&root, 18);
	insert(&root, 10);
	insert(&root, 16);
	insert(&root, 19);
	insert(&root, 17);

	cout << "\nInOrder Traversal: \n";
	InorderTraversal(root);

	cout << "\nPreOrder Traversel: \n";
	PreorderTraversal(root);

	cout << "\nPostOrder Traversal: \n";
	PostOrderTraversal(root);

    cout<<"Before Deletion\t:";
	cout << "\nDisplay: \n";
	InorderTraversal(root);


	cout << "\n---------------delete--------------\n";
	root = deletee(root, 15);
	cout<<"After Deletion\t:";
	cout << "\nDisplay: \n";
	InorderTraversal(root);


	//cout<<"\n=-----------------search---------------\n";
	//search(root,15);

}

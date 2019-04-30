
#include <iostream>
#include <stdlib.h>
using namespace std;

struct NODE
{
	int data;
	NODE ** child;
};

void INSERT(NODE **root,int value, int noOFChild, NODE* hold, int c)
{
	NODE* temp;
	temp=new(NODE);
	temp->data = value;
	//temp->child = (NODE **)malloc(sizeof(NODE)*noOFChild);
	temp->child=new NODE*[noOFChild];
	for(int i=0; i<noOFChild;i++)
	{
		temp->child[i]=NULL;
	}

	if(*root == NULL)
	{
		*root = temp;
	}

	else
	{
		//int a;
		//cout << "Enter child to save value: ";
		//cin >> a;

		hold->child[c]= temp;
	}

}

int main()
{
NODE *root =NULL;
//root,value,noofchild,parent,childno
//(NODE **root,int value, int noOFChild, NODE* hold, int c)

INSERT(&root,1,3,NULL,0);
INSERT(&root,2,1,root,0);
INSERT(&root,5,0,root->child[0],0);
INSERT(&root,3,0,root,1);
INSERT(&root,4,2,root,2);
INSERT(&root,7,0,root->child[2],0);
INSERT(&root,6,0,root->child[2],1);


cout << root->data<<endl;
cout<< root->child[0]->data<<endl;
cout<< root->child[1]->data<<endl;
cout<< root->child[2]->data<<endl;
cout<< root->child[0]->child[0]->data<<endl;
cout<< root->child[2]->child[0]->data<<endl;
cout<< root->child[2]->child[1]->data<<endl;
}

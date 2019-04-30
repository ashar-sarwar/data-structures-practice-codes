#include<iostream>
#include<stdlib.h>
using namespace std;

struct BTNode
{
	int value;
	struct BTNode *LeftChild=NULL;
	struct BTNode *RightChild=NULL;
};

int j=0;
void insert(BTNode **start);
BTNode* BinarySearchTree(BTNode *start);
void display(BTNode *start);
void deletee(BTNode **start);
void insert_recursion(BTNode **start);
BTNode* FindMax(BTNode *start);
BTNode* FindParent(BTNode *start,BTNode *child);
int main()
{
	struct BTNode *root=NULL;
	insert(&root);
    insert(&root);
    insert(&root);
    insert(&root);
    insert(&root);
    insert(&root);
    insert(&root);

    cout<<endl;
    deletee(&root);

    display(root);
}

void insert(struct BTNode **start)
{
	struct BTNode *ptr=(BTNode*)malloc(sizeof(BTNode));
	cin>>ptr->value;
	ptr->LeftChild=NULL;
	ptr->RightChild=NULL;


	if((*start)==NULL)
	{
		*start=ptr;
	}
	else
	{
		struct BTNode *CURR=*start;
		while(CURR!=NULL)
		{
			if(ptr->value >= CURR->value)
			{
				if(CURR->RightChild==NULL)
				{
					CURR->RightChild=ptr;
					break;
				}
				else if(CURR->RightChild!=NULL)
				{
					CURR=CURR->RightChild;
				}
			}
			else if(ptr->value < CURR->value)
			{
				if(CURR->LeftChild==NULL)
				{
					CURR->LeftChild=ptr;
					break;
				}
				else if(CURR->LeftChild!=NULL)
				{
					CURR=CURR->LeftChild;
				}
			}


		}
	}
}

int i=0,input;

BTNode* BinarySearchTree(BTNode *start)
{
    if(i==0)
    {
         cin>>input;
         i++;
    }
    BTNode *CURR=start;
    while(CURR!=NULL)
    {

        if(input==CURR->value)
        {
            return CURR;
        }
        else if(input<CURR->value)
        {
            CURR=CURR->LeftChild;
            BinarySearchTree(CURR);
        }
        else if(input>CURR->value)
        {
            CURR=CURR->RightChild;
            BinarySearchTree(CURR);
        }
    }
    if(CURR==NULL)
    {
        return NULL;
    }
}

void display(BTNode *start)
{
	BTNode *CURR=start;
	if(CURR!=NULL)
	{

		cout<<CURR->value<<endl;

		display(CURR->LeftChild);

		display(CURR->RightChild);
	}

}

void insert_recursion(BTNode **start)
{
    struct BTNode *ptr2=(BTNode*)malloc(sizeof(BTNode));
    ptr2->value=134;
    ptr2->LeftChild=NULL;
    ptr2->RightChild=NULL;
    *start=ptr2;

    struct BTNode *ptr3=(BTNode*)malloc(sizeof(BTNode));
    ptr3->value=112;
    ptr3->LeftChild=NULL;
    ptr3->RightChild=NULL;

    *start=(*start)->LeftChild;
    cout<<"1111";
    *start=ptr3;
}

BTNode* FindMax(BTNode *start)
{
    if(start->RightChild->RightChild==NULL)
    {
        return start;
    }
    else if(start->RightChild!=NULL)
    {
        FindMax(start->RightChild);
    }
}

BTNode* FindParent(BTNode *start,BTNode *child)
{
    if(start->LeftChild==child || start->RightChild==child)
    {
        return start;
    }
    if(start->value > child->value)
    {
        FindParent(start->LeftChild,child);
    }
    if(start->value < child->value)
    {
        FindParent(start->RightChild,child);
    }
}
void deletee(BTNode **start)
{
    struct BTNode *CURR=*start,*parent=(BTNode*)malloc(sizeof(BTNode));
    int input;
    cout<<"Which Number you want to delete:";
    cin>>input;
    while(CURR!=NULL)
    {
        if(input<CURR->value)
        {
            parent=CURR;
            CURR=CURR->LeftChild;
        }
        else if(input>CURR->value)
        {
            parent=CURR;
            CURR=CURR->RightChild;
        }
        if(CURR->value==input)
        {
            break;
        }

    }
    if(CURR->RightChild==NULL && CURR->LeftChild==NULL)
    {
        if(CURR==*start)
        {
            *start=NULL;
        }
        else if(CURR==parent->LeftChild)
        {
            parent->LeftChild=NULL;
            free(CURR);
        }
        else if(CURR==parent->RightChild)
        {
            parent->RightChild=NULL;
            free(CURR);
        }
    }
    else if(CURR->RightChild==NULL && CURR->LeftChild!=NULL)
    {
        if(CURR==*start)
        {
            *start=CURR->LeftChild;
        }
        else if(CURR==parent->LeftChild)
        {
            parent->LeftChild=CURR->LeftChild;
            free(CURR);
        }
        else if(CURR==parent->RightChild)
        {
            parent->RightChild=CURR->LeftChild;
            free(CURR);
        }
    }
    else if(CURR->RightChild!=NULL && CURR->LeftChild==NULL)
    {
        if(CURR==*start)
        {
            *start=CURR->RightChild;
        }
        else if(CURR==parent->LeftChild)
        {
            parent->LeftChild=CURR->RightChild;
            free(CURR);
        }
        else if(CURR==parent->RightChild)
        {
            parent->RightChild=CURR->RightChild;
            free(CURR);
        }
    }
    else if(CURR->RightChild!=NULL && CURR->LeftChild!=NULL)
    {
        struct BTNode *Max=FindMax(CURR->RightChild);
        if(CURR==parent->LeftChild)
        {
            Max->RightChild->LeftChild=CURR->LeftChild;
            Max->RightChild->RightChild=CURR->RightChild;
            parent->LeftChild=Max->RightChild;
            Max->RightChild=NULL;
            free(CURR);
        }
        if(CURR==parent->RightChild)
        {
            Max->RightChild->LeftChild=CURR->LeftChild;
            Max->RightChild->RightChild=CURR->RightChild;
            parent->RightChild=Max->RightChild;
            Max->RightChild=NULL;
            free(CURR);
        }
    }



}

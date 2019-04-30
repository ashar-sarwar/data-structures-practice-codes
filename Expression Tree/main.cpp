#include <iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct EBT
{
    EBT *parent=NULL;
    char value;
    EBT *RightChild=NULL;
    EBT *LeftChild=NULL;
};

void Insert(EBT **tree)
{
    EBT *ptr=(EBT*)malloc(sizeof(EBT)),*CURR=*tree,*Hold=(EBT*)malloc(sizeof(EBT));
    cin>>ptr->value;
    if((*tree)==NULL && (ptr->value>='a' && ptr->value<='z'))
    {
        (*tree)=ptr;
    }
    else if(ptr->value=='+' || ptr->value=='-' ||ptr->value=='*' ||ptr->value=='/')
    {
        if(CURR->LeftChild!=NULL)
        {
            while(CURR->LeftChild!=NULL)
            {
                CURR=CURR->RightChild;
            }
            if(ptr->value=='*' || ptr->value=='/')
            {
                ptr->LeftChild=CURR;
                CURR->parent->RightChild=ptr;
            }
        }
        else
        {cout<<"this";
            ptr->LeftChild=*tree;
            (*tree)->parent=ptr;
            *tree=(*tree)->parent;
        }
    }
    else
    {
        while(CURR->RightChild!=NULL)
        {
            CURR=CURR->RightChild;
        }
        Hold=CURR;
        CURR->RightChild=ptr;
        ptr->parent=CURR;

    }
}
int main()
{
    EBT *tree=NULL;

    Insert(&tree);
    Insert(&tree);
    Insert(&tree);
    Insert(&tree);
    Insert(&tree);

    cout<<endl<<tree->LeftChild->value;
    cout<<tree->value;
    cout<<tree->RightChild->value;
    cout<<tree->RightChild->LeftChild->value;

    cout<<tree->RightChild->RightChild->value;

}

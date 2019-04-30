
#include <iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct NODE
{
    char value;
    struct NODE *Next=NULL;
};
struct BinaryTree
{
    char value;
    struct BinaryTree *RightChild=NULL;
    struct BinaryTree *LeftChild=NULL;
};
struct StackNode
{
    BinaryTree *value;
    struct StackNode *Next=NULL;
};

void push(NODE **top,char value);
char pull(NODE **top);
void InfixToPostfixConversion(NODE *start,NODE **postfix);
void PostfixtoTreeConversion(BinaryTree **root,NODE *postfix);
void display(NODE *start);
void InOrder(struct BinaryTree *Root);
int CheckPrecedence(char value)
{
    if(value=='|')
        return 1;
    else if(value=='&')
        return 2;
    else if(value=='<' || value=='>' || value=='=' || value=='~')
        return 3;
    else if(value=='-' || value=='+')
        return 4;
    else if(value=='/' || value=='*')
        return 5;
    else
        return NULL;

}

void InfixToPostfixConversion(NODE *start,NODE **postfix)
{
    NODE *top=(NODE*)malloc(sizeof(NODE)),*CURR=(NODE*)malloc(sizeof(NODE)),*PostfixCurr=*postfix,*TopCurr;
    CURR=start;
    top=NULL;
    if(CURR==start)
    {
        (*postfix)->value=CURR->value;
        (*postfix)->Next=NULL;
        CURR=CURR->Next;
    }
    while(CURR!=NULL)
    {
        if((CURR->value>='a' && CURR->value<='z')||(CURR->value>='A' && CURR->value<='Z')||(CURR->value>='0' && CURR->value<='9'))
        {
            PostfixCurr->Next=CURR;
            PostfixCurr=PostfixCurr->Next;
        }
        else if(CURR->value=='*' || CURR->value=='+' || CURR->value=='-' || CURR->value=='/' || CURR->value=='=' || CURR->value=='>' || CURR->value=='<' || CURR->value=='~' ||CURR->value=='&' || CURR->value=='|' || CURR->value=='('||CURR->value==')')
        {
            while(1)
            {
                if(top==NULL || CheckPrecedence(top->value)<CheckPrecedence(CURR->value) || CURR->value=='(' || top->value=='(')
                {
                    push(&top,CURR->value);
                    TopCurr=top;
                    break;
                }
                else if( (CheckPrecedence(top->value)>=CheckPrecedence(CURR->value)) && CURR->value != ')' )
                {
                    PostfixCurr->Next=top;
                    PostfixCurr=PostfixCurr->Next;
                    pull(&top);
                }
                else if(CURR->value == ')')
                {
                    while(top->value!='(')
                    {
                        PostfixCurr->Next=top;
                        PostfixCurr=PostfixCurr->Next;
                        pull(&top);
                    }
                    pull(&top);
                    break;
                }

            }
        }
        CURR=CURR->Next;

    }
    while(top!=NULL)
    {
        PostfixCurr->Next=top;
        PostfixCurr=PostfixCurr->Next;
        pull(&top);
    }

}
void display(NODE *start)
{
    struct NODE *CURR=start;
    while(CURR!=NULL)
    {
        cout<<CURR->value;
        CURR=CURR->Next;
    }
}
void insertt(NODE **start)
{
    struct NODE *ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    ptr->value=getche();
    if(*start==NULL)
    {
        *start=ptr;
    }
    else
    {
         struct NODE *CURR=*start;
         while(CURR->Next!=NULL)
         {
             CURR=CURR->Next;
         }
         CURR->Next=ptr;
    }

}

void BTpush(StackNode **top,BinaryTree* value)
{
    StackNode *ptr=(StackNode*)malloc(sizeof(StackNode));
    ptr->value=value;
    ptr->Next=NULL;

    if(*top==NULL)
    {
        *top=ptr;
    }
    else
    {
        ptr->Next=*top;
        *top=ptr;
    }
}
BinaryTree* BTpull(StackNode **top)
{
    StackNode *CURR=*top;
    *top=(*top)->Next;
    return CURR->value;
}
void push(NODE **top,char value)
{
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    ptr->value=value;
    ptr->Next=NULL;

    if(*top==NULL)
    {
        *top=ptr;
    }
    else
    {
        ptr->Next=*top;
        *top=ptr;
    }
}
char pull(NODE **top)
{
    NODE *CURR=*top;
    *top=(*top)->Next;
    return CURR->value;
}
int main()
{

    NODE* Infix=NULL,*Postfix=(NODE*)malloc(sizeof(NODE));
    BinaryTree *root=(BinaryTree*)malloc(sizeof(BinaryTree));
    insertt(&Infix);
    insertt(&Infix);
    insertt(&Infix);
    insertt(&Infix);
    insertt(&Infix);

    InfixToPostfixConversion(Infix,&Postfix);

    cout<<endl<<"Postfix"<<endl;
    display(Postfix);
    PostfixtoTreeConversion(&root,Postfix);
    cout<<endl<<"InOrder Tree"<<endl;
    InOrder(root);



}
void PostfixtoTreeConversion(BinaryTree **root,NODE *postfix)
{
    StackNode *top=(StackNode*)malloc(sizeof(StackNode));
    NODE *CURR=postfix;
    while(CURR!=NULL)
    {
        if((CURR->value>='a' && CURR->value<='z')||(CURR->value>='A' && CURR->value<='Z')||(CURR->value>='0' && CURR->value<='9'))
        {
            BinaryTree *ptr=(BinaryTree*)malloc(sizeof(BinaryTree));
            ptr->value=CURR->value;
            ptr->LeftChild=NULL;
            ptr->RightChild=NULL;
            BTpush(&top,ptr);
        }
        else if(CURR->value=='*' || CURR->value=='+' || CURR->value=='-' || CURR->value=='/' || CURR->value=='=' || CURR->value=='>' || CURR->value=='<' || CURR->value=='~' ||CURR->value=='&' || CURR->value=='|')
        {
            BinaryTree *ptr=(BinaryTree*)malloc(sizeof(BinaryTree));
            ptr->value=CURR->value;
            ptr->RightChild=BTpull(&top);
            ptr->LeftChild=BTpull(&top);
            BTpush(&top,ptr);
        }
        CURR=CURR->Next;
    }
    *root=BTpull(&top);
}
void InOrder(struct BinaryTree *Root)
{
    if(Root!=NULL)
    {
        if(Root->LeftChild!=NULL)
        {
            InOrder(Root->LeftChild);
        }
        cout<<Root->value;
        InOrder(Root->RightChild);
    }

}

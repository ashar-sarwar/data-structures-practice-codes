
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<iostream>
#include<string>
//void Innfix(string);
using namespace std;
/*struct node
{
string value;
struct node *next;
};
/*void Innfix(string input)
{
    for(int i=0;i<input.length();i++)
    {
                cout<<input[i]<<endl;
    }

}*/
struct Evaluate
{
   int value;
   struct Evaluate *next;
};
/*struct Stack
{
   char value;
    struct Stack *next;
};
*/
void push(struct Evaluate **top,int element)
{

    struct Evaluate *ptr;

    ptr=(struct Evaluate*)malloc(sizeof(struct Evaluate));
    ptr->value=element;
//    printf("Pushed value is %d\n",element);
    ptr->next=*top;
      *top=ptr;


}
int pop(struct Evaluate **top)
{
    if(*top==NULL)
    {
        printf("\nStack is underflow");
    }
   if(*top!=NULL)
    {


     struct Evaluate *temp;
    temp=*top;
    (*top)=(*top)->next;
    //printf("%d has popped\n",temp->value);
    free(temp);
    return temp->value;
}
}

/*void peek_stack(struct Stack *start)
{
    struct Stack *curr=start;
    printf("The Elements in a stack are\n");
    while(curr!=NULL)
    {
        printf("%d\n",curr->value);
        curr=curr->next;
    }
}
char Peak(struct Stack *top)
{
    if(top!=NULL)
        return top->value;
}



void push_value(struct Stack **top,char element)
{

    struct Stack *ptr;

    ptr=(struct Stack*)malloc(sizeof(struct Stack));
    ptr->value=element;
//    printf("Pushed value is %d\n",element);
    ptr->next=*top;
      *top=ptr;


}
char pop_value(struct Stack **top)
{
    if(*top==NULL)
    {
        printf("\nStack is underflow");
    }
   if(*top!=NULL)
    {


     struct Stack *temp;
    temp=*top;
    (*top)=(*top)->next;
    //printf("%d has popped\n",temp->value);
    free(temp);
    return temp->value;
}
}





int Check_Precedence(char Operator)
{
 if (Operator=='(')
 {
     return 6;
 }
 else if(Operator=='*'||Operator=='/'||Operator=='%')
 {
     return 5;
 }
 else if(Operator=='+'||Operator=='-')
 {
     return 4;
 }
 else if(Operator=='<'||Operator=='>'||Operator=='='||Operator=='~')
 {
     return 3;
 }
 else if(Operator=='&')
 {
     return 2;
 }
 else if(Operator=='|')
 {
     return 1;
 }
 else if(Operator==')')
 {
     return -1;
 }

}

bool IsEmpty(struct Stack *top)
{
    if(top==NULL)
        return true;
    else
        return false;
}
void insert(struct node **Infix)

{

    struct node *ptr;
    string input;
   ptr=(struct node*)malloc(sizeof(struct node));
   cout<<"\nEnter Infix Expression\t";
   cin>>input;
    ptr->value=input;
    ptr->next=NULL;
    if(*Infix==NULL)
    {
        *Infix=ptr;

    }
    else
    {
    struct node * curr=*Infix;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
         curr->next=ptr;
    }
    }*/
//Innfix(input);
int operatorr (char Operator)
{
    if(Operator=='+'||Operator=='+'||Operator=='-'||Operator=='*'||Operator=='/'||Operator=='%')
    {
        return 1;
    }
    else{
        return 0;
    }

}

void Postfix_Evaluation(){
struct Evaluate *top=NULL;
    string postfix ="ab+";
    //post = postfix;
    int len = postfix.length();
    int value;
           int z=0;

    for(int i=0;i<len;i++){
        if(operatorr(postfix[i]) == 1)
            {  int x = pop(&top);
               int y = pop(&top);


                 if(postfix[i] == '+')
                    {
                       z=y+x;
                        push(&top,(y+x));
                    }


                else if(postfix[i] == '-')
                    {
                         z=y-x;
                        push(&top,(y-x));

                    }

                else if(postfix[i] == '*')
                    {
                         z=y*x;
                        push(&top,(y*x));

                    }

                 else if(postfix[i] == '/')
                    {
                         z=y/x;
                       push(&top,(y/x));

                    }

                else if(postfix[i] == '%')
                    {
                         z=y%x;
                       push(&top,(y%x));

                    }


                }

                else if( ('A'<=postfix[i]&&postfix[i]<='Z') || ('a'<=postfix[i]&&postfix[i]<='z') )
                {
                   cout<<"Please enter the value of"<<postfix[i]<<endl;
                   cin>>value;
                   push(&top,value);
                }
                else if(postfix[i]>='0'&&postfix[i]<='9'){
                     value=postfix[i]-'0';
                     push(&top,value);
                }

        }
           cout<<z;
    }

/*void Infix_Postfix(struct node *Infix)
{
    struct node *curr=Infix;
    struct Evaluate *root=NULL;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    string infix=curr->value;
   // cout<<endl<<infix;

   string postFix = "";
int n = infix.length();
char peak;
int precPeak,precPresent;
//list stack;
struct Stack *top = NULL;


for(int i=0;i<n;i++)
{
 if((infix[i] >= 'A' && infix[i]<= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z')|| (infix[i] >= '0' && infix[i] <= '9'))
  {
  postFix.push_back(infix[i]);
  }
  else
  {
    if(!(IsEmpty(top)))
    {
        peak= Peak(top);
        precPeak = Check_Precedence(peak);
        precPresent =Check_Precedence(infix[i]);
    }
    if(IsEmpty(top) || peak == '(' ||  precPresent > precPeak)
    {
      push_value(&top,infix[i]);
    }

    if(infix[i] == ')')
    {
      while(peak!= '(')
      {
        postFix.push_back(pop_value(&top));
        peak = Peak(top);
      }
      pop_value(&top);
    }

    if(precPresent <= precPeak && peak!= '(')
    {
      while(precPeak >= precPresent && !(IsEmpty(top)))
      {
           postFix.push_back(pop_value(&top));
           precPeak = Check_Precedence(Peak(top));
      }
      push_value(&top,infix[i]);
    }

  }
}

while(!(IsEmpty(top)))
{
  postFix.push_back(pop_value(&top));
}

cout<<"\nPostfix is:\t"<<postFix<<endl;
Postfix_Evaluation(&root,postFix);
}
void display_Infix(struct node *Infix)

{
  struct node * curr=Infix;
    while(curr->next!=NULL)
    {

       // cout<<endl<<"Infix is:  "<<curr->value;
         curr=curr->next;

    }
 cout<<endl<<"Infix is:  "<<curr->value;
}



//void Infix_Postfix
int main()
{
struct node* Infix=NULL;
insert(&Infix);
display_Infix(Infix);
Infix_Postfix(Infix);
cout<<endl<<endl;
insert(&Infix);
display_Infix(Infix);
Infix_Postfix(Infix);*/
int main(){

Postfix_Evaluation();
}







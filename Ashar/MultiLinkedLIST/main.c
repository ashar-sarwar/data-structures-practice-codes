#include <stdio.h>
#include <stdlib.h>

struct Class
{
    char Name;
    struct student *header;
    struct class *next;
};
struct student
{
    char  Name;
    int Seat_NO;
    struct student *next;
};
void insert_class(struct Class **mystart)
{

    char name;
    struct Class *ptr=NULL;
    printf("Enter the name of class\n");
    fflush(stdin);
   scanf("%c",&name);
    ptr=(struct Class*)malloc(sizeof(struct Class));
    ptr->Name=name;
    ptr->next=NULL;
    ptr->header=NULL;
    if(*mystart==NULL){


    *mystart=ptr;
}
else
{

    struct Class *curr=*mystart;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=ptr;
}
}


void insert_student(struct student **header)
{
char name;
int seat_no;
printf("Enter name and seat number of student");
fflush(stdin);
scanf("%c\n%d",&name,&seat_no);
struct student *ptr=NULL;
ptr=(struct student*)malloc(sizeof(struct student));

    ptr->Name=name;
    ptr->Seat_NO=seat_no;

    ptr->next=NULL;
if(*header==NULL)
{
    *header=ptr;
}
else
{

    struct student *curr=*header;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=ptr;
}
}
struct Class* search_class(struct Class *start,int search)
{
    struct Class *curr=start;
    while(curr!=NULL)
    {
        if(search==curr->Name)
        {
            printf("%c class is found\n");
            break;

        }
        curr=curr->next;
    }
    return curr;
}
void search_student(struct Class *start,int seat_no)
{
    struct Class *currClass=start;
    while (currClass!=NULL)
    {
       struct student *currStudent =currClass->header;
      while(currStudent!=NULL)
      {
          if(currStudent->Seat_NO==seat_no)
          {
              printf("%d student found in %d",currStudent,currClass);
              break;
          }
          currStudent=currStudent->next;
      }
      currClass=currClass->next;
    }
}

void delete_student(struct Class **start,int seat_no)
{
struct Class *currClass=*start;
struct student *currStudent=NULL;
while(currClass!=NULL)
{
    currStudent=currClass->header;
   if (currStudent->Seat_NO==seat_no)
    {
        currClass->header=currStudent->next;
        free(currStudent);
    }
    else
    {
        currStudent=(currClass->header)->next;
        struct student *prev=currClass->header;
        while(currStudent!=NULL)
        {
            if(currStudent->Seat_NO==seat_no)
            {
                prev->next=currStudent->next;
                free(currStudent);
                break;
            }
            currStudent=currStudent->next;
            prev=prev->next;

        }
    }
    currClass=currClass->next;
}
}
void Print_Class(struct Class *start)
{
   struct Class *currClass= start;
    while(currClass!=NULL)
    {
        printf("\n\nThe students in class %c are  : \n",currClass->Name);
        struct student *currStudent= currClass->header;
        while(currStudent!=NULL)
        {
           printf("Student %c with seat number %d \n",currStudent->Name,currStudent->Seat_NO);
            currStudent= currStudent->next;
        }
        currClass= currClass->next;
    }
}

void delete_students(struct student **header)
{
    struct student *curr=*header;
    while(curr!=NULL)
    {
        curr=curr->next;
        free(curr);
    }
}
void delete_class(struct Class **start,char name)
{
    struct Class *curr= *start;
    if((*start)->Name==name)
    {
        delete_students(&curr->header);
        *start=(*start)->next;
        free(curr);
    }
    else
    {
       struct Class *curr= (*start)->next;
        struct Class *prev= *start;
        while(curr!=NULL)
        {
            if(curr->Name==name)
            {
                delete_students(&(curr->header));
                prev->next=curr->next;
                free(curr);
                break;
            }
            curr=curr->next;
            prev=prev->next;
        }
    }
}
int main()
{
    struct Class *start=NULL;
    int choice;
    while(1)
    {


   printf("Select any one from the following options\n");
   printf("1.Insert Class\n2.Insert Students\n3.Delete class\n4.Delete Students\n5.Print Class\n6.Exit\n");
   printf("Enter your choice");
   scanf("%d",&choice);
   switch(choice)
   {
   case 1:
       {
        insert_class(&start);
            break;
        }
    case 2:
       {

           char className;
           printf("Enter the name of class to to search");
           fflush(stdin);
           scanf("%c",&className);
          struct Class *curr=search_class(start,className);
           if(curr==NULL)
           {
               printf("No search class found");
               break;
           }
           else
           {
               insert_student(&(curr->header));
               break;
           }


   }
    case 3:
       {


       char className;
           printf("Enter the name of class to to delete");
           fflush(stdin);
           scanf("%c",&className);
           delete_class(&start,className);
            Print_Class(start);
           break;
       }
    case 4:
{

            int Seat_no;
            printf("Enter Seat no of student to delete");
            fflush(stdin);
            scanf("%d",&Seat_no);
            delete_student(&start,Seat_no);
            Print_Class(start);
            break;

        }
        case 5:
        {
        Print_Class(start);
        break;
        }
        case 6:
            exit(0);
            break;
        default:
            printf("Please select a valid choice");
}
}

}

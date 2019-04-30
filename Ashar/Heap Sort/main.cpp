#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;
void heap_Insert(int *,int);
void display(int *,int);
void Swapping(int *,int *);
void Heapify(int *,int);
void heap_Sort(int *,int );
void Delete(int*,int);
int main()
{
    int n;
    cout << "Enter the number of elements in the array" << endl;
    cin>>n;
    cout<<"==================================================Insertion=============================================================";
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=NULL;

    }
    for(int i=0;i<n;i++)
    {
     heap_Insert(arr,n);
    }
cout<<"\n===================================================Before Sorting=======================================================";
    display(arr,n);
   // cout<<"\n=====================================================Before Deletion====================================================";
     //display(arr,n);
     //Delete(arr,n);
    //display(arr,n);
    heap_Sort(arr,n);
     display(arr,n);

    //Delete(arr,n);
    //display(arr,n);
}

void heap_Sort(int *arr,int n)
{
    cout<<"\n\n=========================================After Sorting==================================================================";
    int j=0;
   /* for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }*/
cout<<"\n";
    for(int i=n-1;i>j;i--)
    {
    if(arr[j]>arr[i])
        {
        Swapping(&arr[j],&arr[i]);
       // cout<<arr[j]<<arr[i];
        Heapify(arr,i-1);
        }
    }
}

void Heapify(int *arr,int down)
{
   for(int i=0;i<=down/2;i++)
   {
       if(arr[(2*i)+1]>arr[i]&&(2*i)+1<=down)
       {
           Swapping(&arr[(2*i)+1],&arr[i]);
       }
        if(arr[(2*i)+2]>arr[i]&&(2*i)+2<=down)

       {
           Swapping(&arr[(2*i)+2],&arr[i]);
       }
   }
}

void heap_Insert(int *arr,int n)
{
    int value=0,i=0,curr=0,position=0;
    cout<<"Enter a number to be inserted"<<endl;
    cin>>value;
    for(i=0;i<n;)
    {
        if(arr[i]==NULL)
        {
            arr[i]=value;
            return;
        }
    else if(arr[(2*i)+1]==NULL)
      {
          int curr=(2*i)+1;

          arr[curr]=value;

          while(arr[i]<arr[curr])
          {
                //position=i;
              Swapping(&arr[i],&arr[curr]);
              curr=i;
              i=(i-1)/2;

          }
         // i=position;
          return;
      }
    else   if(arr[(2*i)+2]==NULL)
      {
        int curr=(2*i)+2;
          arr[curr]=value;

          while(arr[i]<arr[curr])
          {
            //position=i;
              Swapping(&arr[i],&arr[curr]);
              curr=i;
              i=(i-1)/2;
          }
           //i=position;
          return;

      }

     i++;
    }

}
void Delete(int *arr,int n)
{

    int i,num;
    cout<<"\n\nEnter a number which you want to delete";
    cin>>num;
    cout<<"\n\n==============================================After Deletion============================================================";
    for(i=0;i<n;)
    {

    if(arr[i]!=num)
    {
        i++;
    }
    else if(arr[i]==num)
    {
        Swapping(&arr[i],&arr[n-1]);
       // cout<<arr[i];
        arr[n-1]=NULL;
        break;
    }
}

while(arr[(2*i)+1]!=NULL||arr[(2*i)+2]!=NULL)
{

     string  t=arr[(2*i)+1]>arr[(2*i)+2]?"IF":"ELSE";
    if(t=="IF")
    {
        if((2*i)+1>n)
            break;
            if(arr[(2*i)+1]>arr[i])
            {
        Swapping(&arr[(2*i)+1],&arr[i]);
            }
     i=(2*i)+1;

    }
    if((2*i)+2>n)
            break;
    if(t=="ELSE")
    {
          if(arr[(2*i)+2]>arr[i])
            {
        Swapping(&arr[(2*i)+2],&arr[i]);

        }
        i=(2*i)+2;
}
}
}

void display(int *arr,int n)
{
    cout<<"\n\n";
    for(int i=0;i<n;i++)
    {
        if(arr[i]==NULL)
        {
           cout<<"Position "<<i<<"\t=\tNULL"<<endl;
        }
        else
        {
           cout<<"Position "<<i<<"=  \t"<<arr[i]<<endl;
        }

    }
}

void Swapping(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

#include<iostream>
using namespace std;
void Binary_Search(int*,int,int,int);
int main()
{
int n,search_no;
cout<<"Enter the no. of Elements in the array";
cin>>n;
cout<<"Enter the elements"<<endl;
int *arr=new int[n];
for(int i=0;i<n;i++)
	cin>>arr[i];
cout<<"Enter a number you want to search";
cin>>search_no;
int l=0;
int u=n-1;

Binary_Search(arr,l,u,search_no);
system("pause");

}

void Binary_Search(int *arr,int l,int u,int search_no)
{
	int flag=0;
	if(l>u)
	{
	cout<<search_no<< " is not found in the array"<<endl;
	}
	else
	{
if(l<=u)
{
int m=(l+u)/2;
if(arr[m]==search_no)
{
	cout<<search_no<<" is found in the array"<<endl;
	flag++;
}
else if(arr[m]<search_no)
{

l=m+1;
Binary_Search(arr,l,u,search_no);
}
else if(arr[m]>search_no)
{
u=m-1;
Binary_Search(arr,l,u,search_no);
}

}
}

}

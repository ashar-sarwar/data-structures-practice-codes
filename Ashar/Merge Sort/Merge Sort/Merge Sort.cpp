
#include <iostream>
using namespace std;
int no_Of_Elements;
void Merge(int*,int,int);
void merge_Sort(int*,int,int);
int main()
{
	cout << "How many Elements you want to Enter in Array" << endl;
	cin >> no_Of_Elements;
	int *arr = new int[no_Of_Elements];
	int start=0,end=no_Of_Elements-1;

	cout << "Enter " << no_Of_Elements << " Elements";

	for (int i = 0; i<no_Of_Elements; i++)
	{
		cin >> arr[i];
	}
	cout<<"Before Sorting the data is"<<endl;
	for (int i = 0; i<no_Of_Elements; i++)
	{
		cout<< arr[i]<<endl;
	}
	merge_Sort(arr,start,end);


	cout<<"After Sorting the data is"<<endl;
	for (int i = 0; i<no_Of_Elements; i++)
	{
		cout<< arr[i]<<endl;
	}
//system("pause");
}

void merge_Sort(int *arr,int start,int end )
{
	if(start<end)
{
int mid_Point=(start+end)/2;
//break the array into two halves
merge_Sort(arr,start,mid_Point);
cout<<"aaya"<<mid_Point;
merge_Sort(arr,mid_Point+1,end);
//Merge the two parts
Merge(arr,start,end);
}
}
void Merge(int *arr,int start,int end)
{
	int mid_Point=(start+end)/2;
	int i=start;
	int j=mid_Point+1;
	int temp=start;
	int k[100];			//Temporarary Array
	while(i<=mid_Point&&j<=end)
	{
	if(arr[i]<arr[j])
	{
	k[temp++]=arr[i++];
	}
	else
	{
		k[temp++]=arr[j++];
	}
	}
	while(i<=mid_Point)
	{

	k[temp++]=arr[i++];

	}
	while(j<=end)
	{
	k[temp++]=arr[j++];
	}
	for(i=start;i<=end;i++)
	{
	arr[i]=k[i];
	}
}

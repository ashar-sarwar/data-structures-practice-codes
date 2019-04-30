//#include<iostream>
//
//using namespace std;
//void Print(int * A)
//{
//	cout << "[";
//	for (int i = 0; i < 10 -1; i++)
//	{
//		cout << A[i]<<", " ;
//	}
//	cout << A[10-1] << "]\n\n";
//}
//void Quicksort(int *A)
//{
//
//}
//
//int main()
//{
//	int myarray[] = {22,55,66,77,88,99,11,33,44,00};
//	Print(myarray);
//
//	system("pause");
//}

#include<conio.h>
#include <iostream>
using namespace std;
void Quick_sort(int*, int, int);
int set_Pivot(int*, int, int);
void Swap(int*,int, int);
void Print(int*);
int no_Of_Elements;
int main()
{

	cout << "How many Elements you want to Enter in Array" << endl;
	cin >> no_Of_Elements;
	int *arr = new int[no_Of_Elements];
	int left = 0, right = no_Of_Elements - 1;

	cout << "Enter " << no_Of_Elements << " Elements";

	for (int i = 0; i<no_Of_Elements; i++)
	{
		cin >> arr[i];
	}

	Quick_sort(arr, left, right);
	cout<<endl<<endl;
	Print(arr);
	//system("pause");
}
void Print(int *arr) {
    cout<<"The sorted array is"<<endl;
	for (int j = 0; j <no_Of_Elements; j++)
	{
		cout << arr[j]<<endl;
	}
}
void Quick_sort(int *arr, int left, int right)
{
	if (left<right)
	{
		int pivot = set_Pivot(arr, left, right);
		Quick_sort(arr, left, pivot - 1);
		Quick_sort(arr, pivot + 1, right);
	}
}

int set_Pivot(int *arr, int left, int right)
{
	int  pivot_index = (left + right) / 2;
	while (left<right)
	{
		if (arr[pivot_index]>arr[right])
		{
			Swap(arr,pivot_index, right);
			pivot_index = right;
		}
		if (arr[pivot_index]<arr[right])
			right--;

		if (arr[pivot_index]<arr[left])
		{
			Swap(arr,pivot_index, left);
			pivot_index = left;
		}
		if (arr[pivot_index]>arr[left])
			left++;
	}
	return pivot_index;


}
void Swap(int* arr,int value_1, int value_2)
{
	int temp = arr[value_2];
	arr[value_2] = arr[value_1];
	arr[value_1] = temp;
}

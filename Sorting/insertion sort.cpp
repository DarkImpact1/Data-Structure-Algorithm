#include<iostream>
using namespace std;
int* InsertionSort(int arr[],int n)
{
	for(int i=1; i<n;i++)
	{
		int temp = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]> temp)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
	return arr;
}
void display(int* arr,int n)
{
	for(int i =0; i<n;i++)
	{
		cout<<arr[i];
	}
}
int main()
{
	int n;
	cout<<"Enter size of array : "<<endl;
	cin>>n;
	int array[n];
	for(int i =0; i<n;i++)
	{
		cin>>array[i];
	}
	int* sortedarray = InsertionSort(array,n);
	display(sortedarray, n);
}

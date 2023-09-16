#include<iostream>
using namespace std;
void BubbleSort()
{
	int size;cout<<"Size of an array : ";cin>>size;
	int arr[size];
	for(int i=0; i<size;i++)
	{
		cin>>arr[i];// taking input from user in an array
	}
	// sorting an array using bubble sort 
	int pass=0,temp;
	for(int i=0; i<size-1;i++)
	{
		for(int j=0; j<size-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
		cout<<"\nthis is : "<<pass<<" pass "<<endl;
		pass++;
	}
	for(int i=0; i<size;i++)
	{
		cout<<arr[i]<<ends;
	}
}

int main()
{
	// arr = 15 16 6 8 5 
	BubbleSort();
	return 0;
}

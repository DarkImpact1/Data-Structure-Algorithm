#include<iostream>
using namespace std;
void OptimisedBubbleSort()
{
	int n;cout<<"Size of an array : ";cin>>n;
	int arr[n];
	for(int i=0; i<n;i++)
	{
		cin>>arr[i];// taking input from user in an array
	}
	
	// sorting an array using optimised bubble sort
	
	int pass=0;//to check how many time loop has been executed 
	
	for(int i=0; i<n-1;i++)//i<n-1--> because last element will be automatically sorted
	{
		int flag=0,temp;
		for(int j=0; j<n-1-i;j++)//j<n-1-i --> to avoid extra comparison
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag = 1;/*in order to check wether swap is take place or not 
				if swapping is not done it means array is sorted and we will break the loop*/
			}
		}
		
		if(flag==0)
		{
			break;
		}
		cout<<"this is : "<< i + 1<<" pass "<<endl;
		pass++;
	}
	for(int i=0; i<n;i++)
	{
		cout<<arr[i]<<ends;
	}
}

int main()
{
	// arr = 16 14 5 6 8
	OptimisedBubbleSort();
	return 0;
}

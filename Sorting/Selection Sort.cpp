#include<iostream>
#include <windows.h>
using namespace std;

void setColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}
void Red()
{
	setColor(4);
}
void Green()
{
	setColor(2);
}
void Blue()
{
	setColor(1);
}
void Cyan()
{
	setColor(3);
}
void Yellow()
{
	setColor(6);
}
void Grey()
{
	setColor(8);
}
void Reset()
{
	setColor(7);
}

void SelectionSort(int arr[], int n)
{
	// to iterate the loop
	for(int i=0;i<n-1;i++)
	{
		int min = i;
		// to find the min in array
		for(int j=i+1;j<n;j++)
		{
			// to update the min
			if(arr[j]<arr[min])
			{
				min = j;
			}
		}
		// swap the element 
		if(min != i)
		{
			int temp;
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
		Red();cout<<"[+] ";Reset();
		Green();cout<<"Iteration ";Reset();Grey();cout<<i+1;Reset();Green();cout<<": ";Reset();
		for(int i=0;i<n;i++)
		{
			Yellow();cout<<arr[i]<<" ";Reset();
		}
		cout<<"\n";
	}	
}
int main()
{
	int n;
	Red();cout<<"[+] ";Reset();
	Green();cout<<"Enter the number of element you want in an array\n";Reset();
	
	Red();cout<<"[-] ";Reset();
	Blue();cin>>n;Reset();
	
	int arr[n];
	
	Red();cout<<"[+] ";Reset();
	Green();cout<<"Enter the elements in an array \n";Reset();
	Red();cout<<"[-] ";Reset();
	for(int i=0;i<n;i++)
	{
		Blue();cin>>arr[i];Reset();
	}
	
	
	SelectionSort(arr,n);
	
	Red();cout<<"[+] ";Reset();
	Green();cout<<"Sorted array : ";Reset();
	for(int i=0;i<n;i++)
	{
		Cyan();cout<<arr[i]<<" ";Reset();
	}
}

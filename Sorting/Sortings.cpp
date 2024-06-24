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

void BubbleSort(int arr[], int n){
	Red();
	cout<<"------------------------------------------------------------------\n";
	cout<<"-                                                                -\n";
	cout<<"-                       ";
	Cyan();cout<<"OPTIMISED BUBBLE SORT";Reset();
	Red();
	cout<<"                    -\n";
	cout<<"-                                                                -\n";
	cout<<"------------------------------------------------------------------\n";
	Reset();
    for(int i=0;i<n-1;i++){
        int swapped = 0;
        for(int j= 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]= temp;
                swapped = 1;
            }
        }
        if(!swapped) {
            cout<<"Already Sorted array "<<endl;
            break;
        }else{
        Red();cout<<"[+] ";Reset();
		Green();cout<<"Iteration ";Reset();Grey();cout<<i+1;Reset();Green();cout<<": ";Reset();
		for(int i=0;i<n;i++)
		{
			Yellow();cout<<arr[i]<<" ";Reset();
		}
		cout<<"\n";
        }
    }
}


void SelectionSort(int arr[], int n)
{
	Red();
	cout<<"------------------------------------------------------------------\n";
	cout<<"-                                                                -\n";
	cout<<"-                       ";
	Cyan();cout<<"SELECTION SORT";Reset();
	Red();
	cout<<"                           -\n";
	cout<<"-                                                                -\n";
	cout<<"------------------------------------------------------------------\n";
	Reset();
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

void insertion_sort(int arr[], int n){
    Red();
	cout<<"------------------------------------------------------------------\n";
	cout<<"-                                                                -\n";
	cout<<"-                       ";
	Cyan();cout<<"INSERTION SORT";Reset();
	Red();
	cout<<"                           -\n";
	cout<<"-                                                                -\n";
	cout<<"------------------------------------------------------------------\n";
	Reset();
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
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
// QUICK SORT

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i=low, j = high;
    while(i < j){
        while(arr[i] <= pivot && i < high){
            i++;
        }
        while(arr[j] > pivot && j > low){
            j--;
        }
        if(i < j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
    
}
void quickSort(int arr[],int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);
        quickSort(arr,low, pIndex-1);
        quickSort(arr,pIndex+1, high);
    }
}
int main()
{	
	while(true){
	int n;
	Red();cout<<"\n[+] ";Reset();
	Green();cout<<"Enter the number of element you want in an array\n";Reset();
	
	Red();cout<<"[-] n >> ";Reset();
	Blue();cin>>n;Reset();
	
	int arr[n];
	
	Red();cout<<"[+] ";Reset();
	Green();cout<<"Enter the elements in an array \n";Reset();
	Red();cout<<"[-] separated by space >> ";Reset();
	for(int i=0;i<n;i++)
	{
		Blue();cin>>arr[i];Reset();
	}
	
	// Asking user's choice for sorting
	bool correct_choice = true;
	Red();cout<<"[+] ";Reset();
	Green();cout<<"SELECT \n\t1 -> SELECTION SORT\n\t2 -> BUBBLE SORT\n\t3 -> INSERTION SORT\n\t4 -> QUICK SORT \n";Reset();
	int choice;
	Red();cout<<"[-] choice >> ";Reset();
	Blue();cin>>choice;Reset();
 	
	
	if(choice == 1){
		SelectionSort(arr,n);
	}else if(choice == 2){
		BubbleSort(arr,n);
	}else if(choice == 3){
		insertion_sort(arr,n);
	}else if(choice == 4){
		    Red();
		cout<<"------------------------------------------------------------------\n";
		cout<<"-                                                                -\n";
		cout<<"-                       ";
		Cyan();cout<<"QUICK SORT    ";Reset();
		Red();
		cout<<"                           -\n";
		cout<<"-                                                                -\n";
		cout<<"------------------------------------------------------------------\n";
		Reset();
		quickSort(arr,0,n-1);
		for(int i=0;i<n;i++)
		{
			Yellow();cout<<arr[i]<<" ";Reset();
		}
	}else{
		Red();cout<<"[+] Wrong choice : Choose number between 1 to 4 ";Reset();
		correct_choice = false;
		break;
	}

	
	if(correct_choice){
	Red();cout<<"[+] ";Reset();
	Green();cout<<"Sorted array : ";Reset();
	for(int i=0;i<n;i++)
	{
		Cyan();cout<<arr[i]<<" ";Reset();
	}
	}
	}
}

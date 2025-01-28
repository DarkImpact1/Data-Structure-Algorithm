// Quick Sort Algorithm

// QUick Sort 

int findIndex(vector<int>&arr, int left, int right){
    int pivot = arr[left];
    int i = left, j = right;
    while(i < j){
        while(arr[i] <= pivot && i <= right){
            i++;
        }
        while(arr[j] > pivot && j >= left){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[left], arr[j]);
    return j;
}
void QuickSort(vector<int>& arr, int left , int right){
    if(left < right){
        int pI = findIndex(arr, left, right);
        QuickSort(arr, left, pI-1);
        QuickSort(arr, pI+1, right);
    }
    
}
int main() {
    vector<int> nums = {4,3,5,6,2,3,1,7};
    QuickSort(nums,0,nums.size()-1);
    for(auto i : nums){
        cout<<i <<" ";
    }

    return 0;
}

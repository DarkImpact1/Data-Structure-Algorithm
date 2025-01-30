// total number of subsequence that can yield  a <= sum <= b;



// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

// 2^n generationg all the subseq and counting only those which can yield a <= sum <= b;
void generateSubSeq(vector<int>& arr, vector<int>temp, int index, int sum, int lower, int  upper){
    if(index == arr.size()){
        for(auto it : temp){
            cout<<it<<" ";
        }
        cout<<": "<<sum<<endl;
        return;
    }
    
    
    temp.push_back(arr[index]);
    sum+= arr[index];
    generateSubSeq(arr,temp,index+1,sum, lower, upper);
    
    temp.pop_back();
    sum -= arr[index];
    generateSubSeq(arr,temp,index+1,sum,lower, upper);
    
}
/*
let's find out the optimised way of doing it 


here's the detailed approach
divide arr into two equal parts then generate all the sub of each part
- sort any one of these 
- count number of possible combination one from sub1, another from sub2 that can yield a<= sum <= b
- since sub2 is sorted then ou can apply binary search to avoid extra computation
-- suppse 
        unsorted                sorted
sub1 = {2,1,-1,4,6} | sub2= {3,3,5,7,9,12,16,18,20}
a =7 b = 15
so for 2 ---- in sorted sub
find  first element which is >= a-2 upperbound i.e 5
and find last element that is <= b-2; lowerbound  i.e 12

*/

int firstEleLessEqaulsX(vector<int> arr, int x){
    int low = 0, high = arr.size()-1;
    int ans = 0;
    while(low <= high){
        int mid = low + (high -low)/2;
        if(arr[mid] <= x){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return ans;
}

int firstEleGreatEqualsX(vector<int> arr, int x){
    int low = 0, high = arr.size()-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= x){ 
            high = mid-1;
        }else{
            low = mid +1;
        }
    }
    return low;
}


void generateSubSeqSum(vector<int>& arr, vector<int>& Sub, int index, int n, int sum) {
    if (index == n) {
        Sub.push_back(sum);
        return;
    }
    
    // Include the current element
    sum += arr[index];
    generateSubSeqSum(arr, Sub, index + 1, n, sum);
    
    // Exclude the current element
    sum -= arr[index];
    generateSubSeqSum(arr, Sub, index + 1, n, sum);
}

int main() {
    vector<int> arr = {-3, 1, 2, 4};
    int n = arr.size();
    int first_half = n / 2;
    
    vector<int> Sub1;
    vector<int> Sub2;
    
    // Generate subsequence sums for the first half
    generateSubSeqSum(arr, Sub1, 0, first_half, 0);
    
    // Generate subsequence sums for the second half
    generateSubSeqSum(arr, Sub2, first_half, n, 0);
    
    // Output the first half subsequence sums
    cout << "First sub: ";
    for (auto el : Sub1) {
        cout << el << " ";
    }
    cout << endl;
    
    // Sort and output the second half subsequence sums
    sort(Sub2.begin(), Sub2.end());
    cout << "Second Sub: ";
    for (auto el : Sub2) {
        cout << el << " ";
    }
    cout << endl;
    
    int A = -2;
    int B = 8;
    
    int total_ans = 0;
    for(auto el : Sub1){
        int i = firstEleGreatEqualsX(Sub2,A-el);
        int j = firstEleLessEqaulsX(Sub2,B-el);
        total_ans += ((j-i)+1);
    }
    cout<<"total number of subset "<<total_ans<<endl;
    
    return 0;
}

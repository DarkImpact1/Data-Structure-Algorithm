/*
K-th element of two Arrays
Difficulty: MediumAccuracy: 37.4%Submissions: 315K+Points: 4
Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

Examples :

Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
Input: a[] = [100, 112, 256, 349, 770], b[] = [72, 86, 113, 119, 265, 445, 892], k = 7
Output: 256
Explanation: Combined sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.
*/

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n1 = a.size(), n2 = b.size();
        int i = 0, j = 0;
        while(i<n1 && j < n2){
            if(a[i] > b[j]){
                if((i+j) == k-1) return b[j];
                j++;
            }else{
                if((i+j) == k-1) return a[i];
                i++;
            }
        }
        while(i < n1){
            if((i+j) == k-1) return a[i];
            i++;
            
        }
        while(j < n2){
            if((i+j) == k-1) return b[j];
                j++;
        }
        return -1;
    }
};

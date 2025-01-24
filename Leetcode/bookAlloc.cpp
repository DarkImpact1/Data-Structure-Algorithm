/*
Problem statement
Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.



There are ‘m’ number of students, and the task is to allocate all the books to the students.



Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.


You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.



If the allocation of books is not possible, return -1.



Example:
Input: ‘n’ = 4 ‘m’ = 2 
‘arr’ = [12, 34, 67, 90]

Output: 113

Explanation: All possible ways to allocate the ‘4’ books to '2' students are:

12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.

12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.

12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.

We are getting the minimum in the last case.

Hence answer is ‘113’.
*/

#include<bits/stdc++.h>
using namespace std;

void updateMinMax(vector<int> &pageArr, int &minPage, int &maxPage){
    int totalPage = 0;
    for(auto page : pageArr){
        if(page > minPage) minPage = page;
        totalPage += page;
    }
    maxPage = totalPage;
}

int numAllocatedStudent(vector<int>& pages, int maxpages){
    int numStu = 1, totalpages = 0;
    for(auto page : pages){
        if((totalpages + page) <= maxpages){
            totalpages += page;
        }else{
            numStu++;
            totalpages = page;
        }
    }
    return numStu;
}
int findPages(vector<int>& pageArr,int size, int numStu){
    if(size < numStu) return -1;
    int minPage = INT_MIN, maxPage;
    updateMinMax(pageArr, minPage, maxPage);
    while(minPage <= maxPage){
        int midPage = (minPage + maxPage)/2;
        int alloStu = numAllocatedStudent(pageArr, midPage);
        if(alloStu <= numStu){
            maxPage = midPage-1;
        }else{
            minPage = midPage+1;
        }
    }
    return minPage;
    
}

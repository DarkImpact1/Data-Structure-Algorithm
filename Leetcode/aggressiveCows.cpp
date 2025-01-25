/*
You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples :

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
  */




bool isPossible(vector<int> &stalls, int numCows, int maxDis){
    int nCow = 1;
    int i = 1;
    int prevPlacedIndex =0;
    while(i < stalls.size()){
        if(stalls[i] - stalls[prevPlacedIndex] >= maxDis){
            prevPlacedIndex = i;
            nCow++;
        }
        i++;
    }
    return nCow >= numCows;
}

int aggressiveCows(vector<int> &stalls, int k) {
    if(stalls.size() < k) return -1;
    sort(stalls.begin(), stalls.end());
    int minD = 1, maxD = stalls[stalls.size()-1]-minD;
    while(minD <= maxD){
        int midD = (midD + maxD)/2;
        if(isPossible(stalls, k, midD)){
            minD= midD+1;
        }else{
            maxD = midD - 1;
        }
    }
    return maxD;
}

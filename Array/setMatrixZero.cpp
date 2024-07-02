#include<bits/stdc++.h>
using namespace std;





int main(){
 vector<vector<int>> vec = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 1, 1}
    };
    // setZero(vec);
    
    for(auto row : vec){
        for(auto ele : row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}
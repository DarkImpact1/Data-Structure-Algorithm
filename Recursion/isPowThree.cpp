// check whether the number is power of three or not 

//recursive way of doing it 
  bool isPowerOfThree(int n){
      if(n<1){
          return false;
      }
      if(n==1){
          return true;
      }
      if(n%3 != 0){
          return false;
      }
      
      return isPowerOfThree(n/3);
  }

// other way of doing it

class Solution {
public:
    bool isPowerOfThree(int n){
        
        while(n >= 3){
            if(n%3 !=0 ) return false;
            n = n/3;
        }
        return n==1;
    }
};

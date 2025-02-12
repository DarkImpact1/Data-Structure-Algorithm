// number of bits that need to flipped to make start to goal


void minBitFlip(){
    int start = 10;//  1010
    int goal = 7;//    0111;
                    // yyny  -> 3 bits need to be flipped
                    
    // appraoch  start ^ goal -> 1101 
    // xor will give us the number of bits that need to be flipped then count number of set bit
    int c= 0, result = start^goal;
    
    while(result != 0){
        c++;
        result = result&(result-1);
    }
    cout<<"number of bits that need to be flipped to make "<<start <<" to "<<goal<<" is : "<<c<<endl;
    
}

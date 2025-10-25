class Solution {
public:
    
    int hammingWeight(int n) {
        int countOfOne = 0;
        for(int i = 1; i<32; i++){
            if((n & 1) == 1){
                countOfOne++;
            }
            n >>= 1;
        }
        return countOfOne;
    }
};
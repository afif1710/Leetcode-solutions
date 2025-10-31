class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        for(int i = 0 ; i<32 ; i++){
            int last_bit = (n & 1);     // Store the last bit
            res = (res << 1) | last_bit;    // left shift res by 1 and OR with last bit
            n >>= 1;            // Right shift n by 1;
        }
        return res;
    }
};
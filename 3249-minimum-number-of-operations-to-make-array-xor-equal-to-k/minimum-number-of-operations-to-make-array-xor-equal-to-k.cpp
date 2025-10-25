class Solution {
public:
    // int countOneBits(int n){
    //     int count = 0;
    //     for(int i = 1; i< 32; i++){
    //         if((n & 1) == 1){
    //             count++;
    //         }
    //         n >>= 1;
    //     }
    //     return count;       // Return number of 1 bits
    // }
    int minOperations(vector<int>& nums, int k) {
        int totalXOR = 0;

        for(auto &num: nums){
            totalXOR = totalXOR ^ num;      // XOR of all numbers
        }
        int difference = totalXOR ^ k;      // Stores the XOR of totalXOR and the desired value 
        // Number of 1 bits is the number of required flips 
        // int numberOfOneBits = countOneBits(difference); 

        int numberOfOneBits = __builtin_popcount(difference);

        return numberOfOneBits;

    }
};
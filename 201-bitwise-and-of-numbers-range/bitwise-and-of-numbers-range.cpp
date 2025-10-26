class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // Time O(log n) for both approach

        // while(right > left){
        //     right = right & (right - 1);    //n & (n-1) unsets the rightmost set bit
        // }
        // return right;

        // Alternative

        int rightShiftCount = 0;
        while(left != right){
            left  >>= 1;
            right >>= 1;       //right shift by 1 bit until left == right
            rightShiftCount++;
        }

        return right << rightShiftCount;    // left shift by the number of right shift
    }
};
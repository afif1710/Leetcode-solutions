class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right > left){
            right = right & (right - 1);    //n & (n-1) unsets the rightmost set bit
        }
        return right;
    }
};
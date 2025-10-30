class Solution {
public:
    bool isPowerOfTwo(int n) {
        int flag = 0;
        if(n > 0 && !(n & (n-1))){
            flag = 1;
        }
        return flag;
    }
};
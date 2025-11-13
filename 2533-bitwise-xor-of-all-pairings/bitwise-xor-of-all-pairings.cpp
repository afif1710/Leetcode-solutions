class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();        
        int m = nums2.size();

        int XOR = 0;

        // if nums1 has odd length, then all values in nums2 will be XOR in result
        if(n % 2 == 1){
            for(auto &num: nums2){
                XOR ^= num;
            }
        }
        // if nums2 has odd length, then all values in nums1 will be XOR in result
        if(m % 2 == 1){
            for(auto &num: nums1){
                XOR ^= num;
            }
        }  

        return XOR;
    }
};
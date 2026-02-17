class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int lastNonZeroFoundAt = 0;
    
        // 1. If the current element is not 0, swap it with the element 
        // at the lastNonZeroFoundAt index
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[lastNonZeroFoundAt], nums[i]);
                lastNonZeroFoundAt++;
            }
        }
        
    }
};
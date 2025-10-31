class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        int total_num = 0;
        int n = nums.size();
        for(int i = 1; i<=n; i++){
            total += i;
        }
        for(int i = 0; i<n; i++){
            total_num += nums[i];
        }

        return (total - total_num);
        
    }
};
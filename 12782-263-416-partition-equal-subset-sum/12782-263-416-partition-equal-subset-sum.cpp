class Solution {
public:
    int n;
    vector<vector<int>> dp;
    bool solve(vector<int>& nums, int i, int target){
        if(i >= n){
            return (target == 0);
        }
        
        if(target < 0){
            return 0;
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        
        int take = solve(nums, i+1, target);
        int not_take = solve(nums, i+1, target - nums[i]);

        return dp[i][target] = (take || not_take); 
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        
        for(int i = 0; i<n; i++){
            sum+=nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        dp.resize(nums.size(), vector<int>(sum / 2 + 1, -1));
        //memset(dp, -1, sizeof(dp));
        int t = sum/2;
        return solve(nums, 0, t);
    }
    
};
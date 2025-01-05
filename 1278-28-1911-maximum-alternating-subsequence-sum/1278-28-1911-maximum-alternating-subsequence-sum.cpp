#define ll long long int
class Solution {
public:
    long long t[100001][2];
    long long solve(vector<int>& nums, int i, bool flag){
        int n = nums.size();
        if(i>=n){
            return 0;
        }
        
        int val = nums[i];
        if(flag == false){
            val = -val;
        }

        if(t[i][flag] != -1){
            return t[i][flag];
        }
        long long take = val + solve(nums, i+1, !flag);
        long long skip = solve(nums, i+1, flag);

        return t[i][flag] = max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        bool flag = true;
        return solve(nums, 0, flag);
    }
};
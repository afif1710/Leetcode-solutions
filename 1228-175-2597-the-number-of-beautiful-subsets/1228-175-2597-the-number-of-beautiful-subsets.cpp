class Solution {
public:
    int res = 0;
    unordered_map<int , int> mp;
    void solve(vector<int> &nums, int k, int idx){
        if(idx>=nums.size()){
            res++;
            return;
        }
        solve(nums, k, idx+1);      //Not take

        if(!mp[nums[idx] + k] && !mp[nums[idx] - k]){
            mp[nums[idx]]++;
            solve(nums, k, idx+1);
            mp[nums[idx]]--;

        }


    }
    int beautifulSubsets(vector<int>& nums, int k) {
        solve(nums, k, 0);
        return res-1;
    }
};
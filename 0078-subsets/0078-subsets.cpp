class Solution {
public:
    vector<vector<int>> res;
    void solve(vector <int> &nums, vector<int>& v, int idx){
        if(idx >= nums.size()){
            res.push_back(v);
            return;
        }
        
        v.push_back(nums[idx]);
        solve(nums, v, idx+1);
        v.pop_back();
        solve(nums, v, idx+1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        int idx = 0;
        solve(nums, v, idx);
        return res;
    }
};
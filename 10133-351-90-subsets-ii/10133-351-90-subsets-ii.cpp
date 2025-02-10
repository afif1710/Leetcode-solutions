class Solution {
public: 
    vector<vector<int>> res;
    void solve(vector<int> &nums, vector<int> &tmp, int idx){
        if(idx>=nums.size()){
            res.push_back(tmp);
            return;
        }
        tmp.push_back(nums[idx]);
        solve(nums, tmp, idx+1);
        tmp.pop_back();

        while(idx+1< nums.size() && nums[idx] == nums[idx+1]){
            idx++;
        }
        solve(nums, tmp, idx+1);


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(begin(nums), end(nums));
        vector<int>tmp;
        solve(nums, tmp, 0);
        return res;
    }
};
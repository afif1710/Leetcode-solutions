class Solution {
public:
    vector<vector<int>> res;
    unordered_set<int>st;
    void solve(vector<int>& nums, vector<int>& tmp){
        int n = nums.size();
        if(tmp.size() == n){
            res.push_back(tmp);
            return;
        }
        for(int i = 0; i<n; i++){
            if(st.find(nums[i]) == st.end()){

                tmp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(nums, tmp);
                tmp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int>tmp;
        solve(nums, tmp);
        return res;
    }
};
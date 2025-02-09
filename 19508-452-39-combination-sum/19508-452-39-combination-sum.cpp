class Solution {
public:
    vector<vector<int>> res;
  
    void solve(vector<int>& candidates, int target, vector<int>& tmp, int idx){
        int n = candidates.size();
        if(target == 0){
            res.push_back(tmp);
            return;
        }
        if(idx>=n || target < 0){
            return ;
        }
        tmp.push_back(candidates[idx]);
        solve(candidates, target - candidates[idx], tmp, idx);
        tmp.pop_back();
        solve(candidates, target, tmp, idx+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        solve(candidates, target, tmp, 0);
        return res;
    }
};
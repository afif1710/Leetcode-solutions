class Solution {
public:

    void solve(vector<int>& candidates, vector<vector<int>>& res, vector<int>& tmp, int idx, int target){
        if(target == 0){
            res.push_back(tmp);
            return;
        }
        if(target < 0 ){
            return;
        }
        unordered_set<int>st;
        for(int i = idx; i<candidates.size(); i++){
            if(i>idx && candidates[i] == candidates[i-1]){
                continue;
            }
            tmp.push_back(candidates[i]);
            solve(candidates, res, tmp, i+1, target-candidates[i]);
            tmp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(begin(candidates), end(candidates));
        solve(candidates, res, tmp, 0, target);
        return res;
    }
};
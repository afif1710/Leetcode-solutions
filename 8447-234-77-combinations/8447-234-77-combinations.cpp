class Solution {
public:
    vector<vector<int>> res;
    void solve(int start, int n, int k, vector<int> &tmp){
        if(k == 0){
            res.push_back(tmp);
            return ;
        }
        if(start > n){
            return;
        }
        tmp.push_back(start);
        solve(start+1, n, k-1, tmp);
        tmp.pop_back();
        solve(start+1, n, k, tmp);
    }
    vector<vector<int>> combine(int n, int k) {
        int start = 1;
        vector<int>tmp;
        solve(start, n, k, tmp);
        return res;
    }
};
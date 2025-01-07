class Solution {
public:
    int n, m;
    int t[1001][1001];
    int solve(vector<vector<int>>& pairs, int i, int p){
        if(i>=n){
            return 0;
        }
        if(p > -1 && t[i][p] != -1){
            return t[i][p];
        }
        int take = 0, skip = 0;
        if(p == -1 || pairs[i][0] > pairs[p][m-1]){
            take = 1+solve(pairs, i+1, i);
        }
        skip = solve(pairs, i+1, p);
        if(p > -1){
            t[i][p] = max(take, skip);
        }
        return max(take, skip);

    }

    int findLongestChain(vector<vector<int>>& pairs) {
        memset(t, -1, sizeof(t));
        n = pairs.size();
        m = pairs[0].size();
        sort(pairs.begin(), pairs.end());
        return solve(pairs, 0, -1);
    }
};
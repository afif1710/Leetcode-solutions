class Solution {
public:
    int m, n;
    int dp[501][501];
    int solve(string &s1, string &s2, int i, int j){
        if(j >= n){
            return m - i; 
        }
        if(i >= m){
            return n - j;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            return dp[i][j] = solve(s1, s2, i+1, j+1);
        }
        int insertion = 1 + solve(s1, s2, i, j+1);
        int deletion = 1 + solve(s1, s2, i+1, j);
        int replace = 1 + solve(s1, s2, i+1, j+1);
        
        return dp[i][j] = min({insertion, deletion, replace});
        
    }
    int minDistance(string s1, string s2) {
        m = s1.length();
        n = s2.length();
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, 0);
    }
};

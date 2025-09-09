class Solution {
public:
    
    int dp[501][501];
    int solve(string &s1, string &s2, int m, int n){
        if(n < 0){
            return m + 1; 
        }
        if(m < 0){
            return n + 1;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        if(s1[m] == s2[n]){
            return dp[m][n] = solve(s1, s2, m - 1, n - 1);
        }
        int insertion = 1 + solve(s1, s2, m, n - 1);
        int deletion = 1 + solve(s1, s2, m - 1, n);
        int replace = 1 + solve(s1, s2, m - 1, n - 1);
        
        return dp[m][n] = min({insertion, deletion, replace});
        
    }
    int minDistance(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, m-1, n-1);
    }
};
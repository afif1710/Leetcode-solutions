class Solution {
public:
    int dp[1001][1001];
    int solve(string &s1, string &s2, int i, int j){
        if(i >= s1.length() || j >= s2.length()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(s1, s2, i+1, j+1);
        }
        
        return dp[i][j] = max(solve(s1, s2, i+1, j), solve(s1, s2, i, j+1));  
        
    }
    int longestCommonSubsequence(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, 0);
    }
};
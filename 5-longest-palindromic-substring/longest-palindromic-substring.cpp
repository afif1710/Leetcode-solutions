class Solution {
public:
    int dp[1001][1001];
    bool isPalindrome(string &s, int l, int r){
        if(l>=r){
            return dp[l][r] = 1;
        }
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        if(s[l] == s[r]){
            return dp[l][r] = isPalindrome(s, l+1, r-1);
        }
        return dp[l][r] = 0;
    }
    int maxlen = INT_MIN;
    int start = -1;
    string longestPalindrome(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(isPalindrome(s, i, j) && (j-i+1 > maxlen)){
                    maxlen = j-i+1;
                    start = i;
                }
            }
        }
        string ans = s.substr(start, maxlen);
        return ans;
    }
};
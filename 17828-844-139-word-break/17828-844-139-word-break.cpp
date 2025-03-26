class Solution {
public:
    unordered_set<string> st;
    int dp[301];
    bool solve(string &s, vector<string>& wordDict, int idx){
        int n = s.length();
        if(idx >= n){
            return 1;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        if(st.find(s) != st.end()){
            return dp[idx] = 1;
        }
        for(int i = 1; i<=n; i++){
            string temp = s.substr(idx, i);
            if(st.find(temp) != st.end() && solve(s, wordDict, idx+i)){
                return dp[idx] = 1;
            }
        }
        return dp[idx] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        for(auto it: wordDict){
            st.insert(it);
        }
        return solve(s, wordDict, 0);
    }
};
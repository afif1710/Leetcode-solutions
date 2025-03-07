class Solution {
public:
    int dp[101];
    int solve(string &s, int idx){
        int n = s.size();
        if(idx>=n){
            return 1;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        if(n == 1 && s[0] != '0'){
            return 1;
        }else if(n == 1 && s[0] == '0'){
            return 0;
        }
        if(s[idx] == '0'){
            return 0;
        }
        int result = solve(s, idx+1);
        int take_both = 0 ;
        if(idx+1 < n){
            if(s[idx] == '1' || (s[idx] == '2' && s[idx+1] <= '6')){
                result += solve(s, idx+2);
            }
        }

        return dp[idx] = result;
    }
    int numDecodings(string s) {
      
        memset(dp, -1, sizeof(dp));
        return solve(s, 0);
        
    }
};
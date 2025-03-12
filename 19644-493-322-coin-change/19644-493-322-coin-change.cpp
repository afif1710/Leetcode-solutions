class Solution {
public:
    int dp[10001];
    int solve(vector<int> &coins, int n, int amount){
        if(amount == 0){
            return 0;
        }
        int res = 1e9;
        if(dp[amount] != -1){
            return dp[amount];
        }
        for(int c: coins){
            if(amount - c >= 0){
                res = min(res, 1 + solve(coins, n, amount-c));
                
            }
        }
        
        return dp[amount] = res;
        
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        int ans =  solve(coins, n, amount);

        return (ans >= 1e9) ? -1 : ans;
    }
};
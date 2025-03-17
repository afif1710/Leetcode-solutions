class Solution {
public:
    int dp[301][5001];
    int solve(vector<int> &coins, int idx, int amount){
        int n = coins.size();
        if(idx == n){
            return 0;
        }
        
        if(amount == 0){
            return 1;
        }
        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }
        if(coins[idx] > amount){
            return solve(coins, idx+1, amount);
        }
        int take = solve(coins, idx, amount-coins[idx]);
        int skip = solve(coins, idx+1, amount);


        return dp[idx][amount] = (skip+take);
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return solve(coins, 0, amount);
    }
};
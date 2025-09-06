class Solution {
public:
    int N, M, K;
    const int MOD = 1e9 + 7;   // 1000000007

    int dp[51][51][101];
    int solve(int idx, int search_cost, int maxVal){
        if(idx >= N){               // Base case
            if(search_cost == K){
                return 1;
            }
            return 0;
        }
        if(dp[idx][search_cost][maxVal] != -1){
            return dp[idx][search_cost][maxVal];
        }
        long int res = 0;
        for(int i = 1; i<=M; i++){
            if(i > maxVal){
                res += solve(idx+1, search_cost+1, i) % MOD;
            }else{
                res +=  solve(idx+1, search_cost, maxVal) % MOD;
            }
        }
        return dp[idx][search_cost][maxVal] = res % MOD;

    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};
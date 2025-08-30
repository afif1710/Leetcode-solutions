class Solution {
public:
    // This is a variation of Longest Increasing Subsequence problem with extra benefit of letting us sort at first as it says we can 
    // take in any order

    int n;
    int dp[1001][1001];
    int solve(int prev, int curr, vector<vector<int>> &pairs){
        if(curr >= n){
            return 0;
        }
        if(prev >= 0 && dp[prev][curr] != -1){
            return dp[prev][curr];
        }
        int take = 0 , skip = 0;
        if(prev == -1 || pairs[prev][1] < pairs[curr][0]){
            take = 1 + solve(curr, curr + 1, pairs);        // when we take, prev -> curr and curr -> curr+1
        }
        skip = solve(prev, curr + 1, pairs);                // when we skip, prev remains same & curr -> curr+1
        if(prev >= 0){
            dp[prev][curr] = max(take, skip);       // when prev != -1
        }
        return max(take, skip);                     // including when prev = -1
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp, -1, sizeof(dp));
        n = pairs.size();
        sort(pairs.begin(), pairs.end());
        return solve(-1, 0, pairs);
    }
};

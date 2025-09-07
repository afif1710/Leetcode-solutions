class Solution {
public:
    //DP problem 

    int solve(vector<int>& nums, vector<bool>& visited, int op, unordered_map<vector<bool>, int> &mp){
        int maxScore = 0;
        int n = nums.size();
        if(mp.find(visited) != mp.end()){      //For memoization
            return mp[visited];
        }
        for(int i = 0; i<n-1; i++){
            if(visited[i]){
                continue;
            }
            for(int j = i+1; j < n; j++){
                if(visited[j]){
                    continue;
                }
                visited[i] = true;
                visited[j] = true;
                
                int score = op * __gcd(nums[i], nums[j]);                  //Score for one combination
                int remainingScore = solve(nums, visited, op+1, mp);      // Score for the remaining combination

                visited[i] = false;                                        //Backtracking
                visited[j] = false;

                maxScore = max(maxScore, score+remainingScore);

            }
        }
        return mp[visited] = maxScore;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n+1, false);
        unordered_map<vector<bool>, int> mp;
        return solve(nums, visited, 1, mp);
    }
};
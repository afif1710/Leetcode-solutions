class Solution {
public:
    // Variant of LIS
    // Recursion + Memoization , O(n2 ⋅ L), L = max length of a string . without dp , time comp. = O(2^n ⋅ L)
    
    int n;
    int dp[1001][1001];
    bool isPred(string &a, string &b){      //Check if a is predecessor of b
        int x = a.length();
        int y = b.length();
        int i = 0, j = 0;
        if(x >= y || y - x != 1){       // length gap shouldn't be more than 1 and b must > a
            return false;
        }
        while(i < x && j < y){
            if(a[i] == b[j]){
                i++;
            }
            j++;
        }
        return (i == x);
    }
    int solve(int prev, int curr, vector<string> &words){        //LIS code
        if(curr >= n){
            return 0;
        }
        // take, skip
        if(prev != -1 && dp[prev][curr] != -1){
            return dp[prev][curr];
        }
        int take = 0, skip = 0;
        if(prev == -1 || isPred(words[prev], words[curr])){
            take = 1 + solve(curr, curr + 1, words);
        }
        skip = solve(prev, curr + 1, words);
        if(prev != -1){
            dp[prev][curr] = max(take, skip);
        }
        return max(take, skip);
    }

    static bool comparator(string &s1, string &s2){     //Sorting based on length of all strings  , O(n logn), constant time comparator
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        memset(dp, -1, sizeof(dp));
        n = words.size();
        sort(words.begin(), words.end(), comparator);
        return solve(-1, 0, words);
    }
};

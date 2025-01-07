class Solution {
public:
    int n;
    int t[1001][1001];
    bool isPred(string &a, string &b){
        int x = a.length();
        int y = b.length();
        if(x>=y || (y-x != 1)){
            return false;
        }
        int i = 0, j = 0;
        while(i<x && j<y){
            if(a[i] == b[j]){
                i++;
            }
            j++;
        }
        return (i == x);
    }
    int solve(vector<string>& words, int i, int p){
        if(i>=n){
            return 0;
        }
        if(p>-1 && t[i][p] != -1){
            return t[i][p];
        }
        int take = 0, skip = 0;
        if(p == -1 || isPred(words[p], words[i])){
            take = 1 + solve(words, i+1, i);
        }
        skip = solve(words, i+1, p);
        if(p > -1){
            t[i][p] = max(take, skip);
        }
        return max(take, skip);
    }

    static bool comparator(string &w1, string &w2){
        return w1.length() < w2.length();
    }

    int longestStrChain(vector<string>& words) {
        memset(t, -1, sizeof(t));
        n = words.size();

        sort(words.begin(), words.end(), comparator);
        return solve(words, 0, -1);
    }
};
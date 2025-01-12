class Solution {
public:
    int n;
    vector<string> curr;
    vector<vector<string>> res;
    bool isPalindrome(string& s, int idx, int i){
        int x = idx;
        int y = i;
        while(x<y){
            if(s[x] != s[y]){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void solve(string& s, int idx, vector<string>& curr){
        if(idx == n){
            res.push_back(curr);
            return;
        }
        for(int i = idx; i<n; i++){
            if(isPalindrome(s, idx, i)){
                curr.push_back(s.substr(idx, i-idx+1));
                solve(s, i+1, curr);
                curr.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        solve(s, 0, curr);
        
        return res;
    }
};
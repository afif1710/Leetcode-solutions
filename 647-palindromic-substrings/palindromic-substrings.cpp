class Solution {
public:

    
    bool isPalindrome(string &s, int i, int j){
        if(i > j){
            return true;
        }
        if(s[i] == s[j]){
            return isPalindrome(s, i+1, j-1);
        }
        return false;
    }
    int solve(string &s, int i, int j, int n){
        int cnt = 0;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(isPalindrome(s, i, j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int n = s.size();
        return solve(s, 0, 0, n);
    }
};
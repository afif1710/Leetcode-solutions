class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int ans = 0, prev = 0, curr = 1;
        for(int i = 1; i<n; i++){
            if(s[i] == s[i-1]){
                curr++;
            }else{
                ans += min(prev, curr);
                prev = curr;        // Prev becomes curr
                curr = 1;           //Start new group
            }
        }
        ans += min(prev, curr);     //For the last group after the loop ends
        return ans;
    }
};
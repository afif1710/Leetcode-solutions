class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> T(26);
        vector<int> S(26);
        int n = t.size();
        for(int i = 0; i<n; i++){
            char ch = t[i];
            int idx = ch - 'a';
            T[idx]++;
        }
        for(int i = 0 ; i < n-1; i++){
            char ch1 = s[i];
            int idx1 = ch1 - 'a';
            S[idx1]++;
        }
        char ans;
        for(int i = 0; i<26; i++){
            if(T[i] > S[i]){
                ans = char('a' + i);
            }
        }
        return ans;
    }
};
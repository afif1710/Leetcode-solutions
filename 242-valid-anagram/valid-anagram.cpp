class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m != n){
            return false;
        }
        unordered_map<char, int> mp;
        unordered_map<char, int> mp1;
        for(int i = 0; i<n ; i++){
            mp[s[i]]++;
            mp1[t[i]]++;
        }
     
        for(int i = 0 ; i<n ; i++){
            int ch = s[i];
            
            int num = mp[ch];
            int num1 = mp1[ch];
            if(num != num1){
                return false;
            }
        }
        return true;
    }
};
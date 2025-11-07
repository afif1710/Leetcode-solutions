class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int mask = 0;
        int final_length = 0;
        unordered_map<int, int> mp;
        mp[mask] = -1;
        int res = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == 'a'){
                mask = mask ^ (1 << 0);
            }else if(s[i] == 'e'){
                mask = mask ^ (1 << 1);
            }else if(s[i] == 'i'){
                mask = mask ^ (1 << 2);
            }else if(s[i] == 'o'){
                mask = mask ^ (1 << 3);
            }else if(s[i] == 'u'){
                mask = mask ^ (1 << 4);
            }
            if(mp.find(mask) != mp.end()){
                res = max(res, i - mp[mask]);
            }else{
                mp[mask] = i;
            }
        }
        return res;
    }
};
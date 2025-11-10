class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int mask = 0;  // bitmask to track parity (even/odd) of vowels
        unordered_map<int, int> mp; 
        mp[mask] = -1; // base case: empty prefix has mask 0 at index -1
        int res = 0;

        for (int i = 0; i < n; i++) {
            // flip corresponding vowel bit when encountered
            if (s[i] == 'a') mask ^= (1 << 0);
            else if (s[i] == 'e') mask ^= (1 << 1);
            else if (s[i] == 'i') mask ^= (1 << 2);
            else if (s[i] == 'o') mask ^= (1 << 3);
            else if (s[i] == 'u') mask ^= (1 << 4);

            // if same mask seen before → substring between has even count of vowels
            if (mp.find(mask) != mp.end()) {
                res = max(res, i - mp[mask]);
            } 
            else {
                // store first occurrence of this mask
                mp[mask] = i;
            }
        }

        return res; // longest substring with even vowel counts
    }
};

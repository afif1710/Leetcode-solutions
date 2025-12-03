class Solution {
public:
    int maxDistinct(string s) {
        string str = s;
        unordered_map<char, int> mp;
        int unique = 1;
        for(int i = 0; i<str.size(); i++){
            mp[str[i]]++;
        }
        return mp.size();
    }
};
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;

        stringstream ss(s);
        string token;
        int countwords = 0;
        while(getline(ss, token, ' ')){
            words.push_back(token);
            countwords++;
        }

        int n = pattern.size();
        int m = words.size();
        unordered_map<char, string> mp;

        if(n != m){
            return false;
        }
        for(int i = 0; i<n ; i++){
            if(mp.find(pattern[i]) == mp.end()){
                for(auto &iterator: mp){
                    if(iterator.second == words[i]){
                        return false;
                    }
                }
                mp[pattern[i]] = words[i];
            }else if(mp.find(pattern[i]) != mp.end()){
                if(words[i] != mp[pattern[i]]){
                    return false;
                }
            }
        }
        return true;


    }
};
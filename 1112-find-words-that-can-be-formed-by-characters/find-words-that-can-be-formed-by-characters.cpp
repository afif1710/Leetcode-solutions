class Solution {
public:
    bool valid(string &word, string &chars, vector<int> &vc1){
        int n = word.size();
        vector<int> vc2(26);
        for(int i = 0; i<n ; i++){
            int ch = word[i] - 'a';
            vc2[ch]++;
        }
        for(int i = 0; i<26 ; i++){
            if(vc2[i] > vc1[i]){
                return false;
            }
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        // unordered_map<char, int> mp;
        vector<int> vc1(26);
        int n = chars.size();
        for(int i = 0;  i<n; i++){
            int ch = chars[i] - 'a';
            vc1[ch]++;
        }
        // int m = words.size();
        long long int ans = 0;
        for(auto word : words){
            if(valid(word, chars, vc1)){
                ans += word.length();
            }
        }
        return ans;
    }
};
class Solution {
public:
    unordered_map<char, string> mp;
    string str = "";
    void solve(vector<string> &res, string digits, int idx){
        if(idx >= digits.size()){
            res.push_back(str);
            return;
        }
        char ch = digits[idx];
        string s = mp[ch];
        for(int i = 0; i<s.size(); i++){
            str.push_back(s[i]);
            solve(res, digits, idx+1);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }
        mp['2'] = "abc"; 
        mp['3'] = "def"; 
        mp['4'] = "ghi"; 
        mp['5'] = "jkl"; 
        mp['6'] = "mno"; 
        mp['7'] = "pqrs"; 
        mp['8'] = "tuv"; 
        mp['9'] = "wxyz"; 

        vector<string> res;
        solve(res, digits, 0);
        return res;



    }
};
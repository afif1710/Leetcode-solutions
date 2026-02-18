class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> v;
        int n = s.size();
        for(int i = n-1; i>=0 ; i--){
            v.push_back(s[i]);
        }
        s = v;
    }
};
class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs) {
        string str = "";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0];
        string last = strs[n - 1];
        int m = min(first.size(), last.size());
        for(int i = 0 ; i<m; i++){
            if(strs[0][i] == strs[n-1][i]){
                str.push_back(strs[0][i]);
            }else{
                break;
            }
        }
        return str;
    }
};
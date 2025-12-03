class Solution {
public:
    int maxDistinct(string s) {
        string str = s;
        sort(str.begin(), str.end());
        int unique = 1;
        for(int i = 1; i<str.size(); i++){
            if(str[i] != str[i-1]){
                unique++;
            }
        }
        return unique;
    }
};
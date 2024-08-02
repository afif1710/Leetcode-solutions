class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int size = s.size();
        
        int k = size-1;
        while(l<k){
            while(!isalnum(s[l]) && l<k){
                l++;
            }
            while(!isalnum(s[k]) && l<k){
                k--;
            }
            if(tolower(s[l]) != tolower(s[k])){
                return false;
            }
            l++;
            k--;
        }
        
        return true;
       
    }
};
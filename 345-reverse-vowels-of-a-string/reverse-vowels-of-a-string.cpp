class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        stack<char> st;
        
        for(int i = 0; i<n ; i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                st.push(s[i]);
                
            }
        }
        string ans = "";
        for(int i = 0; i<n ; i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                ans.push_back(st.top());
                st.pop();
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
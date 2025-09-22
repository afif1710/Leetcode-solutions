class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        if(size%2 == 1){
            return 0;
        }
        stack<char> st;
        for(int i = 0; i<size; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(st.empty()){
                    return 0;
                }else if(s[i] == ')' && st.top() != '('){
                    return 0;
                }else if(s[i] == '}' && st.top() != '{'){
                    return 0;
                }else if(s[i] == ']' && st.top() != '['){
                    return 0;
                }else{
                    st.pop();
                }
            }
        }
        if(st.empty()){
            return 1;
        }else{
            return 0;
        }
    }
};
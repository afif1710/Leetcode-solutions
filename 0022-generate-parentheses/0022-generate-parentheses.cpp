class Solution {
public:
    
    vector<string>st;
    void gen(string &s, int open, int close){
        
        if(open == close && open == 0){
            st.push_back(s);
            return;
        }
        if(open > 0){
            s.push_back('(');
            gen(s, open-1, close);
            s.pop_back();
        }
        if(close>0){
            if(close>open){
                s.push_back(')');
                gen(s, open, close-1);
                s.pop_back();
            }
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        string s = "";
        gen(s, n, n);
        return st;
        
    }
};
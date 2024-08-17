class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        int j = 0, res = 0;
        if(n == 1){
            int tj = stoi(tokens[0]);
            return tj;
        }
        while(j<n){

            if(tokens[j] != "+" && tokens[j] != "-" && tokens[j] != "*" && tokens[j] != "/")             {
                int tmp = stoi(tokens[j]);
                st.push(tmp);
            }else{
                if(tokens[j] == "+"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    res = a + b;
                    st.push(res);

                }else if(tokens[j] == "-"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    res = b - a;
                    st.push(res);


                }else if(tokens[j] == "*"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    res = a * b;
                    st.push(res);


                }else if(tokens[j] == "/"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    res = b / a;
                    st.push(res);


                }
            }

            j++;
        }
        return res;
        }
};
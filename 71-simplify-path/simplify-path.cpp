class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;
        for(int i = 1; i<n ;){
            // skip extra slashes
            while (i < n && path[i] == '/') i++;
            string str = "";
            int j = i;
            while(j<n && path[j] != '/'){
                str.push_back(path[j]);
                j++;
            }
            if(str == "" || str == "."){
                //Do nothing
            }else if(str == ".."){
                if(!st.empty())
                    st.pop();
            }else{
                st.push(str);
            }
            
            i = j;
        }
        string ans = "/";
        vector<string> vc;
        while(!st.empty()){
            vc.push_back(st.top());
            st.pop();
        }
        reverse(vc.begin(), vc.end());
        int sz = vc.size();
        for(int i = 0 ; i<sz ; i++){
            ans+=vc[i];
            if(i < sz-1)
                ans.push_back('/');
        }

        return ans;
    }
};
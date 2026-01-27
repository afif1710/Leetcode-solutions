class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.size();
        int x = 0, y = 0;
        unordered_set<string> st;
        st.insert(to_string(x)+"_"+to_string(y));
        for(int i = 0; i<n; i++){
            if(path[i] == 'N'){
                y++;
            }else if(path[i] == 'S'){
                y--;
            }else if(path[i] == 'E'){
                x++;
            }else if(path[i] == 'W'){
                x--;
            }
            string str = to_string(x) + "_" + to_string(y);
            if(st.find(str) != st.end()){
                return true;
            }
            st.insert(str);
        }
        return false;
    }
};
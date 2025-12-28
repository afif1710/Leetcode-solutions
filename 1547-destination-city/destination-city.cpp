class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        vector<string> a;
        vector<string> b;
        for(auto &path: paths){
            a.push_back(path[0]);
            b.push_back(path[1]);
        }
        string ans = "";
        int flag = 0;
        for(int i = 0; i<n ;i++){
            bool found = false;
            for(int j = 0; j<n ; j++){
                if(b[i] == a[j]){  // Found in a
                    found = true;
                    break;
                }
            }
            if(!found){
                ans = b[i];
            }
            
        }
        return ans;
    }
};
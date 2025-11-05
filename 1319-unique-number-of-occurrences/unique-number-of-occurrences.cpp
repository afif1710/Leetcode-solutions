class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n ; i++){
            mp[arr[i]]++;
        }
        set<int> st;
        for(auto &it: mp){
            int first = it.first;
            int second = it.second;

            if(st.find(second) != st.end()){
                return false;
            }
            st.insert(second);
        }
        return true;
        
    }
};
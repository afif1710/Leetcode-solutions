class Solution {
public:

    vector<pair<int, int>> sortByValue(const map<int, int>& mp){
        
        vector <pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const  pair<int, int>& b) {
        return a.second > b.second; // for descending
    });
    return vec;

    }


    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int, int> mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>> v = sortByValue(mp);
        set <int> st;
        vector <int> ans;
        for(const auto& it: v){
            st.insert(it.first);
            if(st.size() == k){
                break;
            }
        }
        for(auto c: st){
            ans.push_back(c);
        }
        return ans;



    }
};
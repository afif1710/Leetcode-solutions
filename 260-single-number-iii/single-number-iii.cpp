class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        vector<int> res;
        for(auto &it: mp){
            int num = it.first;
            int freq = it.second;
            if(freq == 1){
                res.push_back(num);
            }
        }
        return res;
    }
};
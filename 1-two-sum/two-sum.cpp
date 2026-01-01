class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        vector<int> res;
        for(int i = 0; i<n ; i++){
            int tmp = target - nums[i];
            if(mp.find(tmp) != mp.end() && mp[tmp] != i){
                res.push_back(i);
                res.push_back(mp[tmp]);
                break;
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};
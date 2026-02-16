class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int num: nums){
            mp[num]++;
        }
        int ans;
        int m = n/2;
        for(auto it: mp){
            int num = it.first;
            int freq = it.second;
            if(freq > m){
                ans = num;
                break;
            }
        }
        return ans;
    }
};
class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        int currMax = 1, currMin = 1;
        int m = *max_element(nums.begin(), nums.end());
        int res = m;
        int tmp = 0;
        for(int it: nums){
            tmp = currMax*it;
            currMax = max({it*currMax, it*currMin, it});
            currMin = min({tmp, it*currMin, it});
            res = max(res, currMax);
        }    
        return res;
    }
};
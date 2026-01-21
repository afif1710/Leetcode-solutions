class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int sec_mx = nums[n-2];
        int sec_mn = nums[1];
        int ans = (mx*sec_mx) - (mn*sec_mn);
        return ans;
    }
};
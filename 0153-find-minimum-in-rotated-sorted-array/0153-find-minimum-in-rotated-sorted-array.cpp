class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1, res = nums[r];
        while(l<=r){
            if(nums[l]<nums[r]){
                res = min(res, nums[l]);
                break;
            }
            int m = (l+r)/2;
            if(nums[m] >= nums[l]){
                res = min(res, nums[l]);
                l = m+1;
            }else if(nums[m]<=nums[r]){
                res = min(res, nums[m]);
                r = m-1;
            }
        }
        return res;
    }
};
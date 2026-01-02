class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int prev_prod = 1;
        for(int i = 0; i < n; i++){
            res[i] = prev_prod;
            prev_prod *= nums[i];
        }
        int both = 1;
        for(int i = n-1; i>=0 ; i--){
            res[i] *= both;
            both *= nums[i];
        }
        return res;
    }
};
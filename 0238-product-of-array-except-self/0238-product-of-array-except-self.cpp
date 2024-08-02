class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size, 1);
        int pref = 1;
        for(int i = 0; i<size; i++){
            res[i] = pref;
            pref *= nums[i];
        }
        int post = 1;

        for(int i = size-1;i>=0; i--){
            res[i] *= post;
            post *= nums[i]; 
        }

        return res;
    }
};
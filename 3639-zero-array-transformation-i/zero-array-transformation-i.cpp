class Solution {
public:
    int n, q;
    bool allZeros(vector<int> &nums){
        int flag = 0;
        for(int i = 0 ; i< n ; i++){
            if(nums[i] != 0){
                flag = 1;
                break;
            }
        }
        return flag == 1 ? false : true;
    }
    bool solve(vector<int>& nums, vector<vector<int>>& queries, int k){
        vector<int> diff(n, 0);
        for(int i = 0; i<= k; i++){
            int l = queries[i][0]; //0
            int r = queries[i][1]; //2
            int d = 1;

            diff[l] += d;
            if(r+1 < n)
                diff[r+1] -= d;
        }

        for(int i  = 1; i<n ; i++){
            diff[i] += diff[i-1];
        }

        for(int i = 0; i<n ; i++){
            if(nums[i] > diff[i]){
                return false;
            }
        }
        return true;
    }
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        q = queries.size();
        
        if(allZeros(nums)){
            return true;
        }
        int left = 0;
        int right = q-1;
        bool ans = 0;
        while(left <= right){
            int mid = left + (right-left) / 2;
            if(solve(nums, queries, mid)){
                ans = 1;
                right = mid-1;
                return ans;
            }else{
                left = mid+1;
            }
        }
        return ans;
        
    }
};
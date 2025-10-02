class Solution {
public:
    int n, q;

    bool solve(vector<int> &nums, vector<vector<int>> &queries, int k){
        vector<int> diff(n, 0);

        // Fill out difference array
        for(int  i = 0;  i <= k; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];
            
            diff[l] += x;
            if(r+1 < n){
                diff[r + 1] -= x; 
            } 
        }

        // Finding Cumulative sums of the array elements
        for(int i = 1; i<n; i++){
            diff[i] += diff[i-1];
        }

        for(int i = 0; i < n; i++){
            if(nums[i] > diff[i]){
                return false;
            }
        } 
        return true;

    }

    bool isAllZero(vector<int> &nums){
        int flag = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != 0){
                flag = 1;
                break;
            }
        }
        return flag == 0 ? true : false;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        q = queries.size();
        if(isAllZero(nums)){
            return 0;
        }
        // for(int i = 0; i<q; i++){
        //     if(solve(nums, queries, i) == true){            //Can't use this bcoz it checks entire queries array at the worst case
        //         return i+1;                                 // Hence we will use Binary search instead of this
        //     }
        // }

        int l = 0;
        int r = q-1;
        int res = -1;
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(solve(nums, queries, mid) == true){
                res = mid+1;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }


        return res;
    }
};
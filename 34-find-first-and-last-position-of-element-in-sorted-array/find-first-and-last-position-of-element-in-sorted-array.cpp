class Solution {
public:
    int size;
    int findLeftMost(vector<int>& nums, int target){
        
        int left = 0, right = size - 1;
        int leftMost = -1;
        while(left <= right){
            int mid = left + (right-left) / 2;
            if(nums[mid] == target){
                leftMost = mid;
                right = mid - 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return leftMost;
    }
    int findRightMost(vector<int>& nums, int target){
       
        int left = 0, right = size - 1;
        int rightMost = -1;
        while(left <= right){
            int mid = left + (right-left) / 2;
            if(nums[mid] == target){
                rightMost = mid;
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return rightMost;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        size = nums.size();
        int LM = findLeftMost(nums, target);
        int RM = findRightMost(nums, target);

        return {LM, RM};
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int l = 0, r = row-1;
        int mid;
        while(l<=r){
            mid = (l+r)/2;
            if(target > matrix[mid][col-1]){
                l = mid + 1;
            }else if(target < matrix[mid][0]){
                r = mid - 1;
            }else{
                break;
            }
        }
        if(l>r){
            return false;
        }
        int row1 = mid;
        int top = 0, bot = col-1;
        while(top<=bot){
            mid = (top+bot)/2;
            if(target > matrix[row1][mid]){
                top = mid+1;
            }else if(target < matrix[row1][mid]){
                bot = mid-1;
            }else{
                return true;
            }
        }
        return false;
        
        
    }
};
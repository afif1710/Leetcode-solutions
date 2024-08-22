class Solution {
public:
    
    
    
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int maxLeft = height[l], maxRight = height[r];
        int res = 0;
        
        while(l<=r){
            if(maxLeft <= maxRight){
                maxLeft = max(maxLeft, height[l]);
                res += maxLeft-height[l];
                l++;
            }else{
                maxRight = max(maxRight, height[r]);
                res += maxRight-height[r];
                r--;
            }
        }
        return res;
    }
};
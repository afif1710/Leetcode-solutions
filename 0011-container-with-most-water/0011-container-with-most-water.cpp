class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int size = height.size() - 1;
        int zero = 0;
        int res = 0;
        while(zero < size){
            area = (size - zero)*(min(height[size], height[zero]));
            res = max(res, area);

            if(height[zero] < height[size]){
                zero++;
            }else{
                size--;
            }
        }
        return res;
    }
};
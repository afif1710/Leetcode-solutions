class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n);
        vector<int> right_max(n);
        left_max[0] = height[0];
        right_max[n-1] = height[n-1];
        int prev = height[0];
        for(int i = 1; i<n; i++){
            if(prev > height[i]){
                left_max[i] = prev;
            }else{
                prev = height[i];
                left_max[i] = prev;
            }
        }

        int post = height[n-1];
        for(int i = n-2; i>=0; i--){
            if(post > height[i]){
                right_max[i] = post;
            }else{
                post = height[i];
                right_max[i] = post;
            }
        }
        int ans = 0;
        for(int i = 0; i<n ; i++){
            int tmp = min(left_max[i], right_max[i]) - height[i];
            ans += tmp;
        }
        return ans;


    }
};
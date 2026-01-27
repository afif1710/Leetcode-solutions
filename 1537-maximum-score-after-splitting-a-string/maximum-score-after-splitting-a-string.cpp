class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int total_one = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '1'){
                total_one++;
            }
        }
        if(total_one == 0){
            return n-1;
        }
        int ans = INT_MIN;
        int left_zero = 0;
        int left_one = 0;
        int right_one = 0;
        for(int i = 0; i<n-1; i++){
            if(s[i] == '0'){
                left_zero++;
            }else if(s[i] == '1'){
                left_one++;
            }
            right_one = total_one - left_one;
            ans = max(ans, left_zero + right_one);
        }
        
        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 1;
        int profit = 0, res = 0;

        while(right<prices.size()){
            profit = prices[right] - prices[left];
            res = max(res, profit);
            if(prices[left] > prices[right]){
                left++;
            }else{
                right++;
            }
        }
        return res;
        
    }
};
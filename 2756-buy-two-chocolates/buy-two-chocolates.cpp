class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        int mn = INT_MAX;
        int sec_mn = INT_MAX;
        for(int i = 0; i<n ; i++){
            if(prices[i] <= mn){
                sec_mn = mn;
                mn = prices[i];
            }else if(prices[i] <= sec_mn){
                sec_mn = prices[i];
            }
        }
        if((mn + sec_mn) > money){
            return money;
        }else{
            return (money - (mn + sec_mn));
        }
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX;
        int best = 0;

        for(int p: prices){
            mn = min(mn, p);            //track minimum value so far
            best = max(best, p-mn);     //update best each day
        }
        return best;
    }
};
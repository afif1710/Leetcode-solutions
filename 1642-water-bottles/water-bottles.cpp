class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int remainder = 0 , tmp = 0;

        while(numBottles > 0){
            tmp = numBottles / numExchange;
            if(numBottles < numExchange){
                break;
            }
            remainder = numBottles % numExchange;
            numBottles = (numBottles / numExchange) + remainder;
            ans += tmp;
        }
        cout << ans;
        return ans;
    }
};
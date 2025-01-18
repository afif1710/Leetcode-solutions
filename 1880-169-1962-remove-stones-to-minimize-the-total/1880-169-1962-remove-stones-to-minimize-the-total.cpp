class Solution {
public:
    
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        int sum = 0;
        priority_queue<int> pq(begin(piles), end(piles));
        for(int i = 0; i<n ; i++){
            sum+=piles[i];
        }
        while(k--){
            int temp = pq.top();
            pq.pop();
            int temp1 = (temp/2);
            sum -= temp1;
            temp1 = temp-temp1;
            pq.push(temp1);
        }
        return sum;
        
    }
};
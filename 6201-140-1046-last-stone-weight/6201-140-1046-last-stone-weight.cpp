class Solution {
public:
    priority_queue<int> pq;
    int n;
    int lastStoneWeight(vector<int>& stones) {
        n = stones.size();
        for(int i = 0; i<n; i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int st = abs(a-b);
            pq.push(st);
            
        }
        return pq.top();
    }
};
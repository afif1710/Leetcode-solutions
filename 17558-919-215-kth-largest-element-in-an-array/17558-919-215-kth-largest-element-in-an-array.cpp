class Solution {
public:

    int n;
    priority_queue<int, vector<int>, greater<int>> pq; //Min heap
    int findKthLargest(vector<int>& nums, int k) {
        n = nums.size();
        for(int i = 0; i<n; i++){
            pq.push(nums[i]);
        }
        while(pq.size() != k){
            pq.pop();
        }
        return pq.top();
    }
};
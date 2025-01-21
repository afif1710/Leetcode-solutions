class Solution {
public:

    priority_queue<long long> pq;
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i<n ; i++){
            pq.push(nums[i]);
        }
        long long res = 0;
        while(k--){
            long long tmp = pq.top();
            pq.pop();
            res+=tmp;
            tmp = static_cast<int>(ceil(tmp / 3.0));
            pq.push(tmp);
        }
        return res;
    }
};
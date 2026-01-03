class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // mp[prefixSum] = how many times this prefixSum has occurred so far.
        // We start with prefixSum = 0 occurring once (empty prefix),
        // so subarrays that start at index 0 can be counted.
        mp[0] = 1;

        int res = 0;
        int cumSum = 0;  // running prefix sum

        for (int x : nums) {
            cumSum += x; // update prefix sum up to current index

            // If there was a previous prefix sum = (cumSum - k),
            // then the subarray between that previous point and current index sums to k.
            // Add how many times (cumSum - k) has appeared (could be multiple).
            if (mp.find(cumSum - k) != mp.end()) {
                res += mp[cumSum - k];
            }

            // Record this prefix sum for future subarrays.
            mp[cumSum]++;
        }

        return res;
    }
};

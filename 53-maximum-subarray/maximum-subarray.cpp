class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // curr = best possible sum of a subarray that MUST end at current index
        int curr = nums[0];                                        // start with first element [web:317][web:337]
        
        // best = best (maximum) subarray sum seen anywhere so far
        int best = nums[0];                                        // handles “all negative” arrays correctly [web:317][web:337]

        for (int i = 1; i < (int)nums.size(); i++) {
            // Either:
            // 1) start a new subarray at i (nums[i])
            // 2) extend the previous ending subarray (curr + nums[i])
            curr = max(nums[i], curr + nums[i]);                   // 핵심: "end here" choice [web:317][web:337]

            // The answer could be a subarray that ends at i, so update global best
            best = max(best, curr);                                // track best across all positions [web:317][web:337]
        }

        return best;                                               // maximum subarray sum [web:317]
    }
};

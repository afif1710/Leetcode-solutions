class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) {
            return n; // If k==0, every element qualifies
        }
        sort(nums.begin(), nums.end()); // Sort to find qualification threshold

        long long int ans = 0;
        long long int threshold;

        if (k > 0 && n > k) {
            threshold = nums[n - k]; // The value that sets the "strictly greater" cutoff
        } else if (k > 0 && n <= k) {
            return 0; // No element has k strictly greater elements
        }
        // Count elements strictly less than the threshold
        for (int i = 0; i < n; i++) {
            if (nums[i] < threshold) {
                ans++;
            }
        }
        return ans;
    }
};

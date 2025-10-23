class Solution {
public:

    // Query sum in range [start, end] of segment tree
    long long querySegTree(int start, int end, int i, int l, int r, vector<long long> &segTree){
        if(start > r || end < l) return 0;                 // no overlap
        if(l >= start && r <= end) return segTree[i];      // total overlap
        
        int mid = l + (r - l) / 2;
        long long left = querySegTree(start, end, 2*i+1, l, mid, segTree);
        long long right = querySegTree(start, end, 2*i+2, mid+1, r, segTree);
        return left + right;                               // partial overlap
    }

    // Point update: mark position idx as visited (set 1)
    void updateST(int i, int l, int r, int idx, vector<long long> &segTree){
        if(l == r){
            segTree[i] = 1;                                // mark as seen
            return;
        }
        int mid = l + (r - l) / 2;
        if(idx <= mid) updateST(2*i+1, l, mid, idx, segTree);
        else updateST(2*i+2, mid+1, r, idx, segTree);
        
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];      // update parent
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;                        // maps value -> index in nums2
        int n = nums1.size();

        for(int i = 0; i < n; i++) mp[nums2[i]] = i;

        vector<long long> segTree(4*n, 0);
        long long res = 0;

        // Place first element
        updateST(0, 0, n-1, mp[nums1[0]], segTree);

        // Iterate through nums1 elements
        for(int i = 1; i < n; i++){
            int idx = mp[nums1[i]];                        // current position in nums2

            // count elements before idx already seen
            long long leftCommonCount = querySegTree(0, idx, 0, 0, n-1, segTree);
            long long leftNonCommonCount = i - leftCommonCount;       // rest are unmatched left
            long long elementsAfterIdx = n - 1 - idx;                 // total elements right of idx
            long long rightCommonCount = elementsAfterIdx - leftNonCommonCount; // matched right side

            res += rightCommonCount * leftCommonCount;      // count good triplets

            updateST(0, 0, n-1, idx, segTree);              // mark current as seen
        }
        return res;
    }
};

class Solution {
public:

    long long querySegTree(int start, int end, int i, int l, int r, vector<long long> &segTree){
        if(start > r || end < l){
            return 0;
        }
        if(l >= start && r <= end){
            return segTree[i];
        }
        int mid = l+(r-l)/2;
        long long left = querySegTree(start, end, 2*i+1, l, mid, segTree);
        long long right = querySegTree(start, end, 2*i+2, mid+1, r, segTree);

        return left + right;

    }

    void updateST(int i, int l, int r, int idx, vector<long long> &segTree){
        if(l == r){
            segTree[i] = 1;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid)
            updateST(2*i+1, l, mid, idx, segTree);
        else
            updateST(2*i+2, mid+1, r, idx, segTree);

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];

    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        int n = nums1.size();

        for(int i = 0; i<n; i++){
            mp[nums2[i]] = i;
        }
        vector<long long> segTree(4*n);
        long long res = 0;
        updateST(0, 0, n-1, mp[nums1[0]], segTree);
        for(int i = 1; i<n; i++){
            int idx = mp[nums1[i]];     //index in nums2
            // Searching in Nums2
            long long leftCommonCount = querySegTree(0, idx, 0, 0, n-1, segTree);
            long long leftNonCommonCount = i -  leftCommonCount;
            long long elementsAfterIdx = n - 1 - idx;
            long long righttCommonCount = elementsAfterIdx - leftNonCommonCount;

            res += righttCommonCount * leftCommonCount;

            updateST(0, 0, n-1, idx, segTree);
        }

        return res;
    }
};
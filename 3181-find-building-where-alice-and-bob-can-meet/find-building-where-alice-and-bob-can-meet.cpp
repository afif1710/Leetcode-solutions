class Solution {
public:

    // Build segment tree: each node stores the index of the maximum height in that range
    void buildSegTree(int i, int l, int r, int segTree[], vector<int> &heights){
        if(l == r){
            segTree[i] = l;         // Leaf: store its own index
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegTree(2*i+1, l, mid, segTree, heights);       // Left child
        buildSegTree(2*i+2, mid+1, r, segTree, heights);     // Right child

        // Store index of maximum height between left and right children
        int leftIdx = segTree[2*i+1];
        int rightIdx = segTree[2*i+2];
        segTree[i] = (heights[leftIdx] >= heights[rightIdx]) ? leftIdx : rightIdx;
    }
     
    // Allocate segment tree array and build it
    int *constructSegTree(vector<int> &heights, int n){
        int *segTree = new int[4*n];
        buildSegTree(0, 0, n-1, segTree, heights);
        return segTree;
    }

    // Query segment tree: returns index of max height in range [start, end]
    int querySegTree(int start, int end, int i, int l, int r, int segTree[], vector<int> &heights){
        if(end < l || r < start) return -1;   // No overlap
        if(l >= start && r <= end) return segTree[i];  // Complete overlap

        int mid = l + (r - l)/2;
        int LI = querySegTree(start, end, 2*i+1, l, mid, segTree, heights); // Left child
        int RI = querySegTree(start, end, 2*i+2, mid+1, r, segTree, heights); // Right child
        
        if(LI == -1) return RI;  // Only right valid
        if(RI == -1) return LI;  // Only left valid
        return (heights[LI] >= heights[RI]) ? LI : RI; // Max of both
    }

    // Helper: query max index in [l, r] using segment tree
    int RMIQ(vector<int> &heights, int segTree[], int n, int l, int r){
        return querySegTree(l, r, 0, 0, n-1, segTree, heights);
    }

    // Main function to answer each query
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> res;
        int *segTree = constructSegTree(heights, n);  // Build segment tree once

        for(auto &query: queries){
            int min_idx = min(query[0], query[1]);
            int max_idx = max(query[0], query[1]);

            // If same building or max_idx taller than min_idx, answer is max_idx
            if(min_idx == max_idx){
                res.push_back(min_idx);
                continue;
            } else if(heights[max_idx] > heights[min_idx]){
                res.push_back(max_idx);
                continue;
            }

            // Binary search to find leftmost building taller than both endpoints
            int l = max_idx + 1;
            int r = n - 1;
            int result = INT_MAX;  // Store the index of leftmost taller building

            while(l <= r){
                int mid = l + (r - l)/2;
                int idx = RMIQ(heights, segTree, n, l, mid); // Max index in [l, mid]

                if(heights[idx] > max(heights[max_idx], heights[min_idx])){
                    result = min(result, idx); // Update leftmost
                    r = mid - 1;               // Search left half
                } else {
                    l = mid + 1;               // Search right half
                }
            }

            // If no building taller found, push -1
            if(result == INT_MAX){
                res.push_back(-1);
            } else {
                res.push_back(result);
            }
        }
        return res;
    }
};

class Solution {
public:
    // Build a segment tree where each node stores the maximum capacity
    // available in that node's segment of baskets.
    // i    : current node index in the segment tree array
    // l,r  : range (inclusive) in the original baskets array covered by node i
    // segTree : array representing the segment tree
    // baskets : original baskets capacities
    void buildSegTree(int i, int l, int r, vector<int> &segTree, vector<int> &baskets){
        if(l == r){
            segTree[i] = baskets[l];
            return;
        }
        int mid = l + (r-l)/2;

        buildSegTree(2*i+1, l, mid, segTree, baskets);
        buildSegTree(2*i+2, mid+1, r, segTree, baskets);

        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
    }

    // Try to place a fruit of size 'fruit' into the leftmost basket (index-wise)
    // within the segment [l, r] represented by node i that can accommodate it.
    // Returns true if placement succeeded, false otherwise.
    // Important details a noob should know:
    //  - segTree[i] stores the maximum remaining capacity in this node's segment.
    //  - If segTree[i] < fruit, there is no basket in this entire segment that
    //    can fit this fruit, so we return false immediately (pruning).
    //  - When we reach a leaf (l == r) and it fits, we mark that leaf as used
    //    by setting segTree[i] = -1. We use -1 to represent that the basket
    //    cannot accept any more fruit (effectively zero / unusable).
    //  - After recursively placing a fruit in a child, we update the current
    //    node's value to be the max of its two children so parent nodes remain
    //    correct for subsequent queries.
    bool queryRangeMax(int i, int l, int r, int fruit, vector<int> &segTree){
        // Quick prune: if the max available in this node is less than the fruit
        // size, no basket exists here that can take the fruit.
        if(segTree[i] < fruit){
            return false;
        }
        // If we are at a leaf and the prune above passed, the leaf must be able
        // to accept the fruit. Mark it as used and return true.
        if(l == r){
            segTree[i] = -1; //Assign -1 to the leaf nodes, means fruit was placed
            return true;
        }
        bool placed = false;
        int mid = l + (r-l)/2;
        // Greedy choice: try to place in the left child first (leftmost available
        // basket). We only go left if the left child's max capacity is >= fruit.
        // Otherwise we go right. This ensures we place into the earliest possible
        // basket (by index) that can fit the fruit.
        if(fruit <= segTree[2*i+1]){
            placed = queryRangeMax(2*i + 1, l, mid, fruit, segTree);
        }else{
            placed = queryRangeMax(2*i + 2, mid+1, r, fruit, segTree);
        }
        // After returning from children, update this node's max so future
        // queries see the correct available capacities.
        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
        return placed;
    }

    // Main function: returns the number of fruits that could NOT be placed
    // in any basket.
    // Explanation for a beginner:
    //  - fruits: array of fruit sizes (we try to place them in the given order)
    //  - baskets: array of basket capacities (each basket can hold at most one fruit)
    //  - We build a segment tree over baskets to answer queries quickly:
    //      * Each query asks "is there any basket that can hold this fruit?"
    //      * The tree stores per-node the maximum capacity remaining in that segment.
    //      * Queries traverse the tree top-down to find the leftmost suitable basket.
    //  - If no suitable basket exists for a fruit, we increment 'unplaced'.
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        // Use 4*n as a safe size for the segment tree array to avoid overflow.
        vector<int> segTree(4*n, -1);
        // Build the segment tree using the baskets capacities.
        buildSegTree(0, 0, n-1, segTree, baskets);

        int unplaced = 0;

        // For each fruit, attempt to place it. If queryRangeMax returns false,
        // it means no basket could accommodate this fruit and we count it as
        // unplaced.
        for(int &fruit: fruits){
            if(queryRangeMax(0, 0, n-1, fruit, segTree) == false){
                unplaced++;
            }
        }
        return unplaced;
    }
};

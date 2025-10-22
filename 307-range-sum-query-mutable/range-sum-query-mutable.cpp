class NumArray {
public:
    int n;
    vector<int> segTree;

    // Building Segment Tree
    void buildSegTree(int i, int l, int r, vector<int> &nums){
        if(l == r){
            segTree[i] = nums[l];
            return;
        }
        int mid = l + (r-l)/2;
        buildSegTree(2*i+1, l, mid, nums);
        buildSegTree(2*i+2, mid+1, r, nums);

        segTree[i] = segTree[2*i + 1] + segTree[2*i + 2];
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n);
        buildSegTree(0, 0, n-1, nums);
    }
    
    // Updating a Node at a given index
    void updateNode(int idx, int val, int i, int l, int r){
        if(l == r){
            segTree[i] = val;       //Updating the leaf
            return;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid){
            updateNode(idx, val, 2*i+1, l, mid);
        }else{
            updateNode(idx, val, 2*i+2, mid+1, r);
        }

        segTree[i] = segTree[2*i + 1] + segTree[2*i + 2]; // Updating the parents

    }
    void update(int index, int val) {
        updateNode(index, val, 0, 0, n-1);
    }
    
    //Finding sum of a given range
    int rangeSum(int start, int end, int i, int l, int r){
        if(start > r || end < l || l > r){
            return 0;
        }
        if(l >= start && r <= end){
            return segTree[i];
        }
        int mid = l + (r-l)/2;
        return rangeSum(start, end, 2*i+1, l, mid) + 
                rangeSum(start, end, 2*i+2, mid+1, r);
    }
    int sumRange(int left, int right) {
        return rangeSum(left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
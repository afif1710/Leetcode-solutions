class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;  //Declaring min heap
    int n;
    KthLargest(int k, vector<int>& nums) {
        n = k;
        int size = nums.size();
        for(int i = 0 ; i<size; i++){
            pq.push(nums[i]);
            if(pq.size()>n){           //Everytime the size of PQ gets bigger than k, we pop the top value which is the smallest as this is a min heap and then pq.top() gives us the kth largest value as we r not letting the pq to have elements more than k.
               
                pq.pop();
            
            }
        }
    }
    
    int add(int val) {
        pq.push(val); 
        if(pq.size()>n){        //Same as above
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
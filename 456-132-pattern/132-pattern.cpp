class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int last = INT_MIN;
        for(int i = n-1; i >= 0 ; i--){
            if(nums[i] < last){   // found first value < the last value
                return true;
            }
            while(!st.empty() && nums[i] > st.top()){
                last = st.top();
                st.pop();
            }
            st.push(nums[i]);       //Stores the top value (middle one)
        }
        return false;
    }
};
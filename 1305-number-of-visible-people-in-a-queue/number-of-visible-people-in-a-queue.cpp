class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = 0 ;i<n ; i++){
            while(!st.empty() && heights[i] > heights[st.top()]){
                int j = st.top();
                ans[j]++;           //Sees current person
                st.pop();
            }
            if(!st.empty()){
                ans[st.top()]++;    // If there was a taller person in stack, we increase 1 for him too
            }
            st.push(i);
        }
        return ans;
    }
};
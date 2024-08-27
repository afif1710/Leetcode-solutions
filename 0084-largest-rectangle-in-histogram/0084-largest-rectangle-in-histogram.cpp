class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        vector<int>left(n), right(n);
        for(int i = 0 ;i<n ; i++){
            if(st.empty()){
                left[i] = 0;
                st.push(i);
            }else{
                while(!st.empty() && heights[st.top()] >= heights[i]){
                    st.pop();
                }
                left[i] = st.empty()?0:st.top()+1;
                st.push(i);
            }
        }
        stack<int>st1;
        for(int i = n-1 ;i>=0 ; i--){
            if(st1.empty()){
                right[i] = n-1;
                st1.push(i);
            }else{
                while(!st1.empty() && heights[st1.top()] >= heights[i]){
                    st1.pop();
                }
                right[i] = st1.empty()?n-1:st1.top()-1;
                st1.push(i);
            }
        }
        int mx = 0;
        for(int i = 0; i < n ; i++){
            int d = (right[i] - left[i] + 1) * heights[i];
            mx = max(mx, d);
        }
        return mx;
    }
};
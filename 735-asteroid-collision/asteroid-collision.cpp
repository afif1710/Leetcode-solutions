class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;
       
        for(int i = 0; i<n ; i++){
            int a = asteroids[i];

            // positive asteroids can't collide with previous ones, so push directly
            if (a > 0) {
                st.push(a);
                continue;
            }
            while(!st.empty() && asteroids[i] < 0 && st.top() < abs(asteroids[i]) && st.top() > 0){

                st.pop();
                
            }
            if(!st.empty() && st.top() == abs(asteroids[i])){
                st.pop();
            }else if(st.empty() || st.top() < 0){
                st.push(asteroids[i]);
            }
            
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end()); 
        return ans;
    }
};
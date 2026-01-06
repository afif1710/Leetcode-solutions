class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;            // stack holds surviving asteroids so far
        vector<int> ans;          // final answer (will be built by popping stack)

        for(int i = 0; i<n ; i++){
            int a = asteroids[i];

            // If current asteroid moves right (+), it can't collide with anything on its left now
            if (a > 0) {
                st.push(a);
                continue;
            }

            // Current asteroid moves left (-)
            // Collision is possible only if stack top moves right (st.top() > 0)
            // Pop smaller right-movers that get destroyed by current left-mover
            while(!st.empty() && asteroids[i] < 0 && st.top() < abs(asteroids[i]) && st.top() > 0){
                st.pop();
            }

            // If sizes are equal (top == |current|), both destroy each other => pop top
            if(!st.empty() && st.top() == abs(asteroids[i])){
                st.pop();

            // If stack is empty OR top is also left-moving, then no collision => push current
            }else if(st.empty() || st.top() < 0){
                st.push(asteroids[i]);
            }

            // Note: if stack top is a bigger right-mover, current (-) is destroyed => not pushed
        }

        // Pop survivors from stack into ans (this reverses order)
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        // Reverse to restore left-to-right order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

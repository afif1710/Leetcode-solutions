class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;          // will store surviving asteroids (left -> right order)
        vector<int> ans;

        for (int a : asteroids) {

            // Case 1: moving right => cannot collide with previous asteroids
            if (a > 0) {
                st.push(a);
                continue;
            }

            // Case 2: moving left => may collide with previous right-movers
            // Keep destroying smaller right-movers on top.
            while (!st.empty() && st.top() > 0 && st.top() < -a) {
                st.pop();
            }

            // Now decide the fate of 'a' after all possible pops.
            if (st.empty() || st.top() < 0) {
                // No right-mover to collide with => 'a' survives
                st.push(a);
            } else if (st.top() == -a) {
                // Equal size => both explode
                st.pop();
            }
            // Else: st.top() > -a (bigger right-mover) => 'a' is destroyed (do nothing)
        }

        // Stack -> vector (this reverses order)
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());  // restore left-to-right order

        return ans;
    }
};

class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions {{1,0}, {0, 1}, {0, -1}, {-1, 0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        auto isSafe = [&](int x, int y){
            return x>=0 && x<n && y>=0 && y<m;
        };
        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            int diff = pq.top().first;
            pair<int, int> p = pq.top().second;
            pq.pop();
            int x = p.first;
            int y = p.second;
            if(x == n-1 && y == m-1){
                return diff;
            }
            for(auto &dir: directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                if(isSafe(x_, y_)){
                    int newDiff = abs(heights[x_][y_] - heights[x][y]);
                    int finalDiff = max(newDiff, diff);
                    if(result[x_][y_] > finalDiff){
                        result[x_][y_] = finalDiff;
                        pq.push({finalDiff, {x_, y_}});
                    }
                }
            }

        }

        return result[n-1][m-1];


        
    }
};
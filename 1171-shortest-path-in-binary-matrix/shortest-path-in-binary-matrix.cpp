class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int n;
    bool isSafe(int x, int y){
        if (x >= 0 && y >= 0 && x < n && y < n){
            return true;
        }
        return false;
    }
    vector<vector<int>> directions {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        priority_queue<P, vector<P>, greater<P>> pq;

        if(n == 0 || grid[0][0] != 0){
            return -1;
        }
        vector<vector<int>> result(n, vector<int>(n, INT_MAX));

        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            int dist = pq.top().first;
            pair<int, int> p = pq.top().second;
            int x = p.first;
            int y = p.second;
            pq.pop();

            for(auto dir: directions){
                int d = 1;
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                if(isSafe(x_, y_) && grid[x_][y_] == 0 && (d + dist < result[x_][y_])){
                    result[x_][y_] = d + dist;
                    pq.push({d+dist, {x_, y_}});
                }
            }
        }

        if(result[n-1][n-1] == INT_MAX){
            return -1;
        }else{
            return result[n-1][n-1] + 1;
        }


    }
};
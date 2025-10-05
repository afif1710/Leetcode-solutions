class Solution {
public:
    typedef pair<int, int> P;
    int size;
    int prim(unordered_map<int, vector<P>> &adj){
        int sum = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> visited(size, false);
        pq.push({0, 0});
        
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            int weight = p.first;
            int node = p.second;
            if(visited[node]){
                continue;
            }
            visited[node] = true;
            sum += weight;

            for(auto &vec: adj[node]){
                int adjNode = vec.first;
                int adjWeight = vec.second;

                if(!visited[adjNode]){
                    pq.push({adjWeight, adjNode});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<P>> adj;
        size = points.size();
        for(int i = 0 ; i<size; i++){
            for(int j = i+1; j<size; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        return prim(adj);
    }
};

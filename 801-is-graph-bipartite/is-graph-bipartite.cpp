class Solution {
public:
    int n;
    bool BFS(unordered_map<int, vector<int>> &adj, vector<int> &color, int currNode, int currColor){
        queue<int> que;
        color[currNode] = currColor;
        que.push(currNode);
        
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(int &v: adj[u]){
                if(color[v] == color[u]){
                    return false;
                }
                if(color[v] == -1){
                    int newColor = 1 - color[u];
                    color[v] = newColor;
                    que.push(v);
                }
            }
        }

        return true;

        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        unordered_map<int, vector<int>> adj;

        for(int u = 0; u<n ; u++){
            for(int v = 0; v<graph[u].size(); v++){
                adj[u].push_back(graph[u][v]);
            }
        }
        vector<int> color(n, -1);
        for(int i = 0 ; i<n; i++){
            if(color[i] == -1 && !BFS(adj, color, i, 1)){
                return false;
            }
        }
        return true;
        
    }
};
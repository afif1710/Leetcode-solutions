class Solution {
public:
    int n;
    void DFS(vector<vector<int>>& isConnected, vector<bool> &visited, int u){
        visited[u] = true;

        for(int v = 0 ; v<n ; v++){
            if(!visited[v] && isConnected[u][v] == 1){
                DFS(isConnected, visited, v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool> visited(n+1, false);
        visited[0] = NULL;
        int cnt = 0;
        for(int i = 0 ; i<n ; i++){
            if(!visited[i]){
                // cnt++;
                DFS(isConnected, visited, i);
                cnt++;
            }
        }
        return cnt;

    }
};
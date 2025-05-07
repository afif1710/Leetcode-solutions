class Solution {
public: 
   
    bool isCycleBFS(unordered_map<int , vector<int>>& adj, vector<int>& indeg, int V, int cnt){
        
        queue<int> qu;
        for(int i = 0; i<V; i++){
            if(indeg[i] == 0){
                qu.push(i);
            }
        }

        while(!qu.empty()){
            int u = qu.front();
            qu.pop();
            cnt++;
            for(auto &v: adj[u]){
                indeg[v]--;
                if(indeg[v] == 0){
                    qu.push(v);
                }
            }
        }
        if(cnt == V){
            return true;
        }else{
            return false;
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int V = numCourses;
        unordered_map<int , vector<int>> adj;
        vector<int> indeg(V, 0);

        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];
            //b -----> a
            adj[b].push_back(a);
        }
        for(int u = 0; u<V; u++){
            for(auto &v: adj[u]){
                indeg[v]++;
            }
        }
        int cnt = 0;
        return isCycleBFS(adj, indeg, V, cnt);


    }
};
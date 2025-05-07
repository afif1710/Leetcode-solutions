class Solution {
public:
    int V;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        V = numCourses;

        unordered_map<int, vector<int>> adj;

        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
        }

        vector<int> indeg(V, 0);

        for(int u = 0; u<V; u++){
            for(auto &v: adj[u]){
                indeg[v]++;
            }
        }
        int cnt = 0;
        queue<int> qu;
        vector<int> res;
        for(int i = 0; i<V; i++){
            if(indeg[i] == 0){
                qu.push(i);
            }
        }

        while(!qu.empty()){
            int u = qu.front();
            res.push_back(u);
            cnt++;
            qu.pop();

            for(auto &v: adj[u]){
                indeg[v]--;
                if(indeg[v] == 0){
                    qu.push(v);
                }
            }
        }

        if(cnt != V){
            return {};
        }else{
            return res;
        }


        




    }
};
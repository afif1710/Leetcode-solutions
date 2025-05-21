class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;

    int find(int x){            //Find function
    if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int par_x = find(x);
        int par_y = find(y);

        if(par_x == par_y) 
            return ;

        if(rank[par_x] > rank[par_y]){
            parent[par_y] = par_x;
        }else if(rank[par_x] < rank[par_y]){
            parent[par_x] = par_y;
        }else{
            parent[par_y] = par_x;
            rank[par_x]++;
        }

    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i<n ; i++){
            parent[i] = i;
        }
        int comp = n;

        for(auto &vec: connections){
            int u = vec[0];
            int v = vec[1];
            if(find(u) != find(v)){
                Union(u, v);
                comp--;
            }
        }
        return comp-1;
    }
};
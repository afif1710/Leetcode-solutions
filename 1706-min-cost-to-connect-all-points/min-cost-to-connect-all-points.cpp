class Solution {
public:
    typedef pair<int, int> P;
    int size;
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


    int kruskal(vector<vector<int>> &vec){
        int sum = 0;
        
        for(auto &tmp: vec){
            int u = tmp[0];
            int v = tmp[1];
            int w = tmp[2];

            int par_u = find(u);
            int par_v = find(v);
            
            if(par_u != par_v){
                Union(par_u, par_v);
                sum += w;
            }
            
        }
 
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        // unordered_map<int, vector<P>> adj;
        vector<vector<int>> vec;
        size = points.size();
        parent.resize(size);
        rank.resize(size, 0);
        for(int i = 0 ; i<size; i++){
            parent[i] = i;
        }
        for(int i = 0 ; i<size; i++){
            for(int j = i+1; j<size; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                vec.push_back({i, j, dist});
                // vec.push_back({j, i, dist});
            }
        }
        auto comparator = [&](vector<int> &v1, vector<int> &v2){
            return v1[2] < v2[2];
        };
        sort(vec.begin(), vec.end(), comparator);
        return kruskal(vec);
    }
};
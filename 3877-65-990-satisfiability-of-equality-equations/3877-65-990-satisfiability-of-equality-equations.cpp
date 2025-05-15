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
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);
        for(int i = 0; i<26; i++){
            parent[i] = i;
        }
        for(auto &s: equations){
            if(s[1] == '='){
                char a = s[0] - 'a';
                char b = s[3] - 'a';
                Union(a, b);
            }
        } 
        for(auto &s: equations){
            if(s[1] == '!'){    // a!=b
                char a = s[0] - 'a';
                char b = s[3] - 'a';
                int par_a = find(a);
                int par_b = find(b);

                if(par_a == par_b){
                    return false;
                }
            }
        } 
        return true;

    }
};
class Solution {
public:
    int n, m, first_x = 0, first_y = 0, pos_path = 0, result = 0;

    vector<vector<int>> direction{{1,0}, {-1, 0}, {0, 1}, {0, -1}};

    void solve(vector<vector<int>>& grid, int i, int j, int count){
        
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == -1){
            return;
        }
        if(grid[i][j] == 2){
            if(count == pos_path){
                result++;             
            }
            return;
        }

        grid[i][j] = -1;
        for(auto &dir: direction){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            solve(grid, new_i, new_j, count+1);
        }
        grid[i][j] = 0;


    }


    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 || grid[i][j] == 0){
                    pos_path++;
                }
                if(grid[i][j] == 1){
                    first_x = i;
                    first_y = j;
                }
            }
        }
        solve(grid, first_x, first_y, 0);
        return result;
    }
};
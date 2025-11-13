class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        //For the first column to make sure it consists all 1
        for(int i = 0; i<row; i++){
            if(grid[i][0] == 0){
                for(int j = 0; j<col; j++){
                    if(grid[i][j] == 0){
                        grid[i][j] = 1;
                    }else{
                        grid[i][j] = 0;
                    }
                }
            }
        }
        // From the 2nd columns
        for(int i = 1; i<col; i++){
            int cntZero = 0;
            for(int j = 0; j<row; j++){
                if(grid[j][i] == 0){
                    cntZero++;
                }
            }
            int cntOne = row - cntZero;
            if(cntZero > cntOne){
                //Flip that entire column
                for(int j = 0; j<row; j++){
                    grid[j][i] = 1 - grid[j][i];
                }
            }
        }

        //Count score from the Modified Grid
        long long int score = 0;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                long long int tmp = pow(2, col - j - 1);
                score += tmp * (grid[i][j]);
            }
        }
        return score;
    }
};
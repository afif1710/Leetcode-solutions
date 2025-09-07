class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
    
        int left = 2;
        int x = coordinates[0][0];
        int y = coordinates[0][1];
        int new_x = coordinates[1][0];
        int new_y = coordinates[1][1];
        int subX = new_x - x;
        int subY = new_y - y;
        while(left < n){
            int a = coordinates[left][0];
            int b = coordinates[left][1];
            int new_subX = a - x;
            int new_subY = b - y;
            if(subX * new_subY == subY * new_subX){
                left++;
            }else{
                return false;
            }

        }
        return true;
    }
};
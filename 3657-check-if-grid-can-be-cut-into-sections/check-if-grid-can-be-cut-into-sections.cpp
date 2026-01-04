class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        
        vector<vector<int>> x;
        vector<vector<int>> y;
        for(int i = 0; i<rectangles.size(); i++){
            int x1 = rectangles[i][0];
            int x2 = rectangles[i][2];
            int y1 = rectangles[i][1];
            int y2 = rectangles[i][3];
            x.push_back({x1, x2});
            y.push_back({y1, y2});
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int tmp_x = 0, tmp_y = 0;
        int last_x = x[0][1];
        for(int i = 1; i<x.size(); i++){
            int first_x = x[i][0];
            int sec_x = x[i][1];
            if(first_x >= last_x){      //No overlap
                tmp_x++;
            }
            last_x = max(last_x, sec_x);
        }
        int last_y = y[0][1];
        for(int i = 1; i<y.size(); i++){
            int first_y = y[i][0];
            int sec_y = y[i][1];
            if(first_y >= last_y){      //No overlap
                tmp_y++;
            }
            last_y = max(last_y, sec_y);

        }
        if(tmp_x >= 2 || tmp_y >= 2){
            return true;
        }else{
            return false;
        }
    }
};
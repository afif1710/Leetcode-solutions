class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back({intervals[0][0], intervals[0][1]});
        for(int i = 1; i<n; i++){
            int x = intervals[i][0];
            int y = intervals[i][1];
            vector<int> tmp = res.back();
            int tmp_x = tmp[0];
            int tmp_y = tmp[1];
            if(x <= tmp_y){
                res.pop_back();
                int mn = min(x, tmp_x);
                int mx = max(y, tmp_y);
                res.push_back({mn, mx});
            }else{
                res.push_back({x, y});
            }
        }
        return res;
    }
};
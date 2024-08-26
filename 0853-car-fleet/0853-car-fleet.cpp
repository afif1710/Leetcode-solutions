class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        vector<pair<double, double>> v;
        for(int i=0; i<n; i++){
            v.push_back({(double)position[i], (double)speed[i]});
        }
        sort(v.begin(), v.end());
        vector<double>res(n);
        int tmp = 0;
        for(int i = n-1; i>=0; i--){
            double tm = (double)((target - v[i].first)/v[i].second);
            res[i] = tm;
            if(i<=n-2 && res[i] <= res[i+1]){
                res[i] = res[i+1];
            }else{
                tmp++;
            }
        }
        
        return tmp;
    }
};
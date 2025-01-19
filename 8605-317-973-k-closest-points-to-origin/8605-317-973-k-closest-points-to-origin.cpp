class Solution {
public:
    struct lambda {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            // Compare based on squared Euclidean distance from the origin
            return (a[0] * a[0] + a[1] * a[1]) > (b[0] * b[0] + b[1] * b[1]);
        }
    };
    priority_queue<vector<int>, vector<vector<int>>, lambda> pq;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        
        for(int i = 0;i<n; i++){
            pq.push(points[i]);
        }
        vector<vector<int>> res;
        for(int i = 0; i<k; i++){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;

    }
};
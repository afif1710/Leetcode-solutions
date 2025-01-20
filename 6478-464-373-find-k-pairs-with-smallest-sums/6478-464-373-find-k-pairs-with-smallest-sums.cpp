class Solution {
public:

    typedef pair<int, pair<int, int>> p;
    priority_queue<p, vector<p>, greater<p>> pq; //Min heap
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        set<pair<int, int>> visited;
        int add = nums1[0] + nums2[0];
      
        pq.push({add, {0, 0}});
        visited.insert({0, 0});
        vector<vector<int>> res;
      
        
        while(k-- && !pq.empty()){
            auto tmp = pq.top();
            pq.pop();

            int i = tmp.second.first;
            int j = tmp.second.second;

            res.push_back({nums1[i], nums2[j]});

            if(i+1<n && (visited.find({i+1, j}) == visited.end())){
                pq.push({nums1[i+1] + nums2[j], {i+1, j}});
                visited.insert({i+1, j});
            }
            if(j+1 < m && (visited.find({i, j+1}) == visited.end())){
                pq.push({nums1[i] + nums2[j+1], {i, j+1}});
                
                visited.insert({i, j+1});
            }
        }
        return res;
    }
};
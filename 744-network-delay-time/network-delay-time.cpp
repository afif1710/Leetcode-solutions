class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto &time: times){
            int u = time[0];
            int v = time[1];
            int w = time[2];

            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res(n+1, INT_MAX);
        res[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            int Node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(auto &vec: adj[Node]){
                int adjNode = vec.first;
                int d       = vec.second;

                if(dist + d < res[adjNode]){
                    res[adjNode] = dist+d;
                    pq.push({dist+d, adjNode});
                }
            }
        }

        int ans = INT_MIN;
        for(int i = 1; i<= n ; i++){
            if(res[i] > ans){
                ans = res[i];
            }
        }

        return (ans == INT_MAX) ? - 1 : ans;
        

    
    }
};
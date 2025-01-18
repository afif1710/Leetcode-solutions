class Solution {
public:
    unordered_map<char, int> mp;
    int n;
    typedef pair<char, int> P;
    struct lambda{
        public:
            bool operator()(P &p1, P &p2){
                return p1.second <= p2.second;
            }
    };
    string frequencySort(string s) {
        n = s.size();
        for(char &ch: s){
            mp[ch]++;
        }
        priority_queue<P, vector<P>, lambda> pq;

        for(auto &it: mp){
            pq.push({it.first, it.second});
        }
        string res = "";
        while(!pq.empty()){
            P tmp = pq.top();
            pq.pop();
            res += string(tmp.second, tmp.first);
        }
        return res;


    }
};
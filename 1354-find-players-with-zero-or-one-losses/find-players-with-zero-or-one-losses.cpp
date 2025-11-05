class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int, int> mp;
        for(auto &match: matches){
            int loser = match[1];
            mp[loser]++;
        }
        vector<int> not_lost;
        vector<int> lost_once;
        for(auto &it: matches){
            int winner = it[0];
            int loser = it[1];
            if(mp.find(winner) == mp.end()){
                not_lost.push_back(winner);
                mp[winner] = 2;
            }
            if(mp[loser] == 1){
                lost_once.push_back(loser);
            }
        }

        sort(begin(not_lost), end(not_lost));
        sort(begin(lost_once), end(lost_once));

        return {not_lost, lost_once};
    }
};
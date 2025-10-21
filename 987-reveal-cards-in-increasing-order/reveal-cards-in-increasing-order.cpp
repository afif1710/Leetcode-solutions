class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> qu;
        for(int i = 0; i<n ; i++){
            qu.push(i);
        }
        vector<int> res(n);
        for(int i = 0 ; i<n ; i++){
            int idx = qu.front();
            qu.pop();
            res[idx] = deck[i];
            if(!qu.empty()){
                qu.push(qu.front());
                qu.pop();
            }
        }
        return res;
    }
};
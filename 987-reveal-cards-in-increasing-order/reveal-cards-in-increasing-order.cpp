class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> qu;
        for(int i = 0; i<n ; i++){      //Fill queue with indices
            qu.push(i);
        }
        vector<int> res(n);
        for(int i = 0 ; i<n ; i++){
            int idx = qu.front();   //Get the top index 
            qu.pop();
            res[idx] = deck[i];     //then input ith value
            if(!qu.empty()){        //if queue is not empty
                qu.push(qu.front());    //then take the top element push in the queue
                qu.pop();           //then pop it
            }
        }
        return res;
    }
};
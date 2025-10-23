class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int unplaced = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(baskets[j] >= fruits[i] && visited[j] == false){
                    visited[j] = true;
                    break;
                }
            }
        }
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                unplaced++;
            }
        }
        return unplaced;
    }
};
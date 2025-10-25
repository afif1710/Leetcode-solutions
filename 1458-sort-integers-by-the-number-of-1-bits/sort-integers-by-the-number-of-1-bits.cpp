class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [] (int &a, int &b){
            int countOneInA = __builtin_popcount(a); 
            int countOneInB = __builtin_popcount(b);

            if(countOneInA == countOneInB){
                return a < b;
            } 
            return countOneInA < countOneInB;      // Returns the number which has less 1 bits 
        };
        sort(arr.begin(), arr.end(), lambda);

        return arr;
    }
};
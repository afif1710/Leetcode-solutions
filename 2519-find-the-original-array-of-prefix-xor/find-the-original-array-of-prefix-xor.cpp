class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        // for(int i = n-1; i > 0; i--){
        //     pref[i] = pref[i] ^ pref[i-1];      //XOR
        // }
        // return pref;



        //Alternative
        
        vector<int> res(n);
        res[0] = pref[0];
        for(int i = 1; i < n; i++){
            res[i] = pref[i] ^ pref[i-1];      //XOR
        }

        return res;

    }
};
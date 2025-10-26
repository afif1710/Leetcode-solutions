class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> preComputeXOR(n);
        preComputeXOR[0] = arr[0];
        for(int i = 1 ; i<n ; i++){
            preComputeXOR[i] = arr[i] ^ preComputeXOR[i-1];
        }
        vector<int> res;
       
        for(auto &query: queries){
            int startIdx = query[0];
            int endIdx   = query[1];
            int ans;
            if(startIdx == 0){
                ans = preComputeXOR[endIdx];    // Return the toal length XOR
            }else{
                // Else (Xor of right) ^ (Xor till left - 1) gives the (Xor from left to right) 
                ans = preComputeXOR[endIdx] ^ preComputeXOR[startIdx - 1];
            }
            res.push_back(ans);
        }
        return res;
    }
};
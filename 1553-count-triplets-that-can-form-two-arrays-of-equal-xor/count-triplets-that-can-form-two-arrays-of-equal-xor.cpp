class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // Prefix XOR array to store XOR from start up to current index
        vector<int> res(arr.begin(), arr.end());
        for(int i = 1; i < arr.size(); i++){
            res[i] = res[i-1] ^ arr[i];  // Build prefix XOR
        }
        res.insert(res.begin(), 0);  // Insert 0 at start to handle full-prefix cases

        int n = res.size();
        int cnt = 0;

        // Iterate through all pairs (i, k)
        for(int i = 0; i < n; i++){
            for(int k = i + 1; k < n; k++){
                // If prefix XORs are equal, XOR between i and k-1 is zero
                if(res[i] == res[k]){
                    cnt += k - i - 1;  // Count valid j values between i and k
                }
            }
        }
        return cnt;
    }
};

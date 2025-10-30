class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> res(arr.begin(), arr.end());
        for(int i = 1; i<arr.size(); i++){
            res[i] = res[i-1] ^ arr[i];
        }
        res.insert(res.begin(), 0);
        int n = res.size();
        int cnt = 0;
        for(int i = 0; i<n ; i++){
            for(int k = i+1; k<n; k++){
                if(res[i] == res[k]){
                    cnt = cnt + k - i - 1;
                }
            }
        }
        return cnt;


    }
};
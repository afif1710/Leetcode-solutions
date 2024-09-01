class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int res = r;
        while(l<=r){
            int mid = (l+r)/2;
            long long int hour = 0;
            for(int i = 0; i<n ; i++){
                //int tmp = ceil(static_cast<double>(piles[i])/h);
                //hour+=tmp;
                hour += ceil(static_cast<double>(piles[i])/mid);
            }
            
            if(hour<=h){
                res = min(res, mid);
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return res;
    }
};
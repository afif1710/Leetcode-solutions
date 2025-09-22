class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> isPrime(n+1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i*i <= n; i++){
            if(isPrime[i]){
                for(int j = 2; i*j <= n; j++){
                    isPrime[i*j] = false;
                }
            }
        }
        for(int i = 2; i<=n; i++){
            if(isPrime[i]){
                cnt++;
            }
        }
    
        if(isPrime[n]){
            cnt--;
        }
        return cnt;
    }
};

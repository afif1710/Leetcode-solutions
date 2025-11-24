class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> vc;
        while(n > 0){
            int rem = n % 10;
            n = n / 10;
            if(rem != 0)
                vc.push_back(rem);
        }
        int tmp = 1;
        int sum = 0;
        for(int i = 0; i<vc.size(); i++){
            sum+=vc[i];
        }
        long long int ans = 0;
        for(int i = 0; i<vc.size(); i++){
            ans += vc[i] * tmp;
            tmp = tmp * 10;
        }
        return ans*sum;
    }
};
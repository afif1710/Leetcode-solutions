class Solution {
public:
    int kthFactor(int n, int k) {
        int ans;
        for(int i = 1; i*i < n; i++){    // <= hobe na bcoz input 4 and 4 hoile same number 2 bar count hoye 2 bar k-- hobe
            
            if(n%i == 0){
                k--;
            }
            if(k == 0){
                return i;
            }
            
        }
        
       
        
        if(k > 0){
            for(int i = sqrt(n); i > 0; i--){
                
                if(n%i == 0){
                    k--;
                }
                if(k == 0){
                    return n/i;
                }
                
            }
        }
        if(k < 0){
            ans = -1;
        }
        return ans;
    }
};
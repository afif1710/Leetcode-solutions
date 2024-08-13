class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size();
        int i = 0, j = 0, mx = 0, res = 0;
        vector <int> vc(26);
        
        while(j<size){
            vc[s[j] - 'A']++;
            mx = max(mx, vc[s[j] - 'A']);
            if((j-i+1) - mx > k){
                vc[s[i] - 'A']--; 
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};
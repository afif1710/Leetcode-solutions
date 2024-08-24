class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        
        if(n1 < n2) return "";
        unordered_map <char , int> mp;
        for(int i = 0; i<n2; i++){
            mp[t[i]]++;
        }
        
        int l = 0, start_i = 0, r = 0;
        int req = n2, ws =INT_MAX;
        while(r<n1){
            char ch = s[r];
            
            if(mp[ch]>0){
                req--;
            }
            mp[ch]--;
            
            while(req == 0){
                
                int cws = r-l+1;
                if(ws>cws){
                    ws = cws;
                    start_i = l;
                }
                
                
                mp[s[l]]++;
                
                if(mp[s[l]] > 0){
                    req++;
                }
                l++;
            }
            r++;
        }
        
        if(ws == INT_MAX){
            return "";
        }else{
            return s.substr(start_i, ws);
        }
        
        
    }
};
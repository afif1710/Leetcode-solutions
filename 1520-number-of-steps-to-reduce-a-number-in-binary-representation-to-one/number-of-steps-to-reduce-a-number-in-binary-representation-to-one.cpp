class Solution {
public:
    void add_one(string &s){
        int last = s.size() - 1;
        while(last >= 0 && s[last] == '1'){
            s[last] = '0';
            last--;
        }
        if(last < 0)
            s.insert(s.begin(), '1');
        else{
            s[last] = '1';
        }

    }
    int numSteps(string s) {
        int cnt = 0;
        while(s.size() != 1){
            int n = s.size() - 1;
            if(s[n] == '0'){
                s.pop_back();
                
            }else{
                add_one(s);
            }
            cnt++;
            
        }
        return cnt;
    }
};
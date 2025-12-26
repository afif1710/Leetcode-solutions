class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        unordered_map<char, int> mp;
        for(int i = 0; i<n; i++){
            mp[num[i]]++;
        }
        string tmp = "";
        int mx = -1;
        for(int i = 0; i<n-2; i++){
            if(mp[num[i]] >= 3){
                if(num[i] == num[i+1] && num[i] == num[i+2]){
                    int st = num[i] - '0';
                    mx = max(mx, st);
                }
            }
        }
        char ch = mx + '0';
        if(mx == -1){
            tmp = "";
        }else{
            tmp.push_back(ch);
            tmp.push_back(ch);
            tmp.push_back(ch);
        }
        return tmp;
    }
};
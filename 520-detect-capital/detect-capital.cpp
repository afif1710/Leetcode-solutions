class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int cnt1 = 0, cnt2 = 0;
        for(int i = 1 ; i<n ; i++){
            int ch = word[i] - 'A';
            if(ch < 26){
                cnt1++;
            }else{
                cnt2++;
            }
        }
        int tmp = word[0] - 'A';
        if(cnt1 && cnt2){
            return false;
        }else if(tmp > 26 && cnt1 && !cnt2){
            return false;
        }
        return true;
    }
};
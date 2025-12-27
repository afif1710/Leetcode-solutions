class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int tmp = -1;
        for(int i = n-1; i >= 0; i--){
            int integer = num[i] - '0';
            if(integer % 2 == 1){
                tmp = i;
                break;
            }
        }
        string ans = "";
        if(tmp == -1){
            return ans;
        }else{
            for(int i = 0; i<=tmp ; i++){
                ans.push_back(num[i]);
            }
            return ans;
        }
    }
};
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && x % 10 == 0)){
            return false;
        }
        int reversed_half = 0;
        while(x > reversed_half){
            reversed_half  = reversed_half * 10 + (x % 10);
            x = x/10;
        }
        return (x == reversed_half || x == reversed_half/10);  // if x == 12321 then x becomes 12 and rev becomes 123. so to make rev equal to x we divided it by 10
    }
};
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        while(a != 0 || b != 0 || c != 0){
            if((c & 1) == 1){
                if((a & 1) == 0 && (b & 1) == 0){
                    flips++;
                }
                // else if((a & 1) == 1 && (b & 1) == 1){
                //     flips++;     // This condition is wrong bcoz in Bitise OR 1 + 1 = 1
                // }            
            }else if((c & 1) == 0){     //Braces is a must
                if((a & 1) == 1){
                    flips++;
                }
                if((b & 1) == 1){
                    flips++;
                }
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return flips;
    }
};
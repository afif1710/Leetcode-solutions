class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for(int k = 0; k < 32; k++){
            int countOne = 0;
            for(auto &num: nums){
                int kLeftShift = 1 << k;
                if((num & kLeftShift) != 0){    //kLeftShift can be 1,2,4,8... not just 0 or 1
                    countOne++;
                }
            }
            if(countOne % 3 == 1){  //Since other nums appear 3 times
                int kLeftShift = 1 << k;
                res = res | kLeftShift;
            }   
        }
        return res;
    }
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0; // final answer (we’ll build it bit by bit)

        // iterate through all 32 bits of an int (17 works here but 32 is safer)
        for (int k = 0; k < 32; k++) {
            int cntOne = 0; // count how many numbers have 1 at this bit position

            for (auto &num : nums) {
                int tmp = 1 << k;             // isolate the k-th bit mask (1, 2, 4, 8, ...)
                if ((num & tmp) != 0)         // if the k-th bit of num is set
                    cntOne++;                 // count it
            }

            // if 1s appear an odd number of times, that bit belongs to the unique number
            if (cntOne % 2 == 1)
                res |= (1 << k);              // set that bit in the result
        }

        return res; // the number that appears once
    }
};

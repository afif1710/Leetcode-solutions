class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int Xor = 0;

        // Step 1: XOR all numbers → leaves XOR of the two unique numbers
        for (int num : nums) {
            Xor ^= num;
        }

        // Step 2: Extract rightmost set bit of Xor (bit where the two unique numbers differ)
        unsigned int temp = Xor;
        int complement = temp & -temp;


        int grpA = 0, grpB = 0;

        // Step 3: Split numbers into two groups based on that differing bit
        for (int num : nums) {
            if (num & complement)
                grpA ^= num;   // XOR in group A
            else
                grpB ^= num;   // XOR in group B
        }

        // Step 4: Each group now contains exactly one unique number
        return {grpA, grpB};
    }
};

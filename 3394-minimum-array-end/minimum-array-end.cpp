class Solution {
public:
    long long minEnd(int n, int x) {

        // We start from x because the first number in the sequence is x.
        long long num = x;

        // We need to generate the (n-1) next numbers:
        // Each time:
        //   1. Increase num by 1
        //   2. Force all bits that are 1 in x to remain 1 using OR with x
        //
        // This guarantees num always stays in the "allowed numbers" defined by x.
        for (int count = 1; count < n; count++) {
            num = (num + 1) | x;
        }

        // After n−1 steps, 'num' becomes the nth valid number.
        return num;
    }
};

class Solution {
public:
    // add 1 to binary string s (handles carries, may increase length)
    void add_one(string &s){
        int last = s.size() - 1;

        // flip trailing '1's to '0' until we find a '0' or run out
        while(last >= 0 && s[last] == '1'){
            s[last] = '0';
            last--;
        }

        // if carry propagated past front, insert leading '1'
        if(last < 0)
            s.insert(s.begin(), '1');
        else
            s[last] = '1';
    }

    int numSteps(string s) {
        int cnt = 0;

        // iterate until s becomes "1"
        while(s.size() != 1){
            int n = s.size() - 1;

            if(s[n] == '0'){
                // even -> divide by 2 (remove LSB)
                s.pop_back();
            } else {
                // odd -> add 1 (may flip many bits / insert at front)
                add_one(s);
            }
            cnt++;
        }
        return cnt;
    }
};

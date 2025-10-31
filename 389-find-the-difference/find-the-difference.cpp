class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> T(26); // frequency count for string t
        vector<int> S(26); // frequency count for string s
        int n = t.size();

        // count each character in t
        for (int i = 0; i < n; i++) {
            char ch = t[i];
            int idx = ch - 'a'; // convert 'a'..'z' → 0..25
            T[idx]++;
        }

        // count each character in s
        for (int i = 0; i < n - 1; i++) {
            char ch1 = s[i];
            int idx1 = ch1 - 'a';
            S[idx1]++;
        }

        // find the character with higher count in t
        char ans;
        for (int i = 0; i < 26; i++) {
            if (T[i] > S[i]) {
                ans = char('a' + i); // convert index back to char
            }
        }

        return ans; // return the extra character
    }
};

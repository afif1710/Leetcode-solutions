class Solution {
public:

    struct TrieNode {
        TrieNode* left;   // represents bit 0
        TrieNode* right;  // represents bit 1
        TrieNode() : left(NULL), right(NULL) {} // important: initialize pointers
    };

    // Insert a number into the binary trie (bit-by-bit from MSB → LSB)
    void insert(TrieNode* root, int &num) {
        TrieNode* crawler = root;

        for (int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1;  // extract the i-th bit of the number

            if (ith_bit == 1) {            // if bit is 1 → go/create right child
                if (crawler->right == NULL)
                    crawler->right = new TrieNode();
                crawler = crawler->right;
            } else {                       // if bit is 0 → go/create left child
                if (crawler->left == NULL)
                    crawler->left = new TrieNode();
                crawler = crawler->left;
            }
        }
    }

    // Find the maximum XOR for a given number using the trie
    int findMaxXor(TrieNode* root, int &num) {
        int mx = 0;
        TrieNode* crawl = root;

        for (int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1;      // extract bit

            // To maximize XOR: try to go OPPOSITE bit if possible
            if (ith_bit == 1) {
                if (crawl->left != NULL) {     // opposite of 1 is 0
                    mx += (1 << i);            // XOR gains a 1 at this bit
                    crawl = crawl->left;
                } else {
                    crawl = crawl->right;      // no opposite → settle for same bit
                }
            } else {                            // bit is 0
                if (crawl->right != NULL) {     // opposite of 0 is 1
                    mx += (1 << i);             // XOR gains a 1 at this bit
                    crawl = crawl->right;
                } else {
                    crawl = crawl->left;
                }
            }
        }
        return mx;
    }

    // Main function: build trie and compute max XOR pair
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();        // start with empty trie

        // Insert all numbers into trie
        for (int &num : nums)
            insert(root, num);

        int maxXor = 0;

        // For each number, find best possible XOR match stored in trie
        for (int &num : nums)
            maxXor = max(maxXor, findMaxXor(root, num));

        return maxXor;
    }
};

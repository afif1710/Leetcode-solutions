class Solution {
public:

    struct TrieNode{
        TrieNode* left;    // represents bit 0
        TrieNode* right;   // represents bit 1
    };
    

    // Insert a number into the binary trie (bitwise from MSB → LSB)
    void insert(TrieNode* root, int &num){
        TrieNode* crawler = root;
        for(int i = 31; i>= 0; i--){                   // iterate through all 32 bits
            int ith_bit = (num>>i) & 1;               // extract the i-th bit of num

            if(ith_bit){                              // if bit is 1 → go to right child
                if(crawler->right == NULL){           // create node if missing
                    crawler->right = new TrieNode();
                }
                crawler = crawler->right;             // move downward
            }else{                                     // if bit is 0 → go to left child
                if(crawler->left == NULL){            // create node if missing
                    crawler->left = new TrieNode();
                }
                crawler = crawler->left;              // move downward
            }
        }
    }

    // Find the maximum XOR value achievable with num by traversing trie
    int findMaxXor(TrieNode* root, int &num){
        int mx = 0;
        TrieNode* crawl = root;

        for(int i = 31; i>= 0 ;i--){                  // check from MSB → LSB
            int ith_bit = (num>>i) & 1;               // extract i-th bit of num

            // To maximize XOR: choose the opposite bit if available
            if(ith_bit == 1){
                if(crawl->left != NULL){              // prefer 0 to maximize XOR with 1
                    mx += pow(2, i);                  // set this bit in result
                    crawl = crawl->left;
                }else{
                    crawl = crawl->right;             // fallback: same bit path
                }
            }else{                                     // num's bit is 0
                if(crawl->right != NULL){             // prefer 1 to maximize XOR
                    mx += pow(2, i);                  // set this bit in result
                    crawl = crawl->right;
                }else{
                    crawl = crawl->left;              // fallback
                }
            }
        }
        return mx;                                    // maximum XOR with this num
    }

    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();              // create empty trie root

        // Insert all numbers into the trie
        for(int &num: nums){
            insert(root, num);
        }

        int maxXor = 0;

        // For each number, find the maximum XOR achievable with other numbers
        for(int i = 0; i<nums.size(); i++){
            int temp = findMaxXor(root, nums[i]);     // find best XOR partner
            maxXor = max(maxXor, temp);               // update global maximum
        }

        return maxXor;                                // return final result
    }
};

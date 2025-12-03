class Solution {
public:

    struct TrieNode{
        TrieNode* left;    //0
        TrieNode* right;   //1
    };
    

    void insert(TrieNode* root, int &num){
        TrieNode* crawler = root;
        for(int i = 31; i>= 0; i--){
            int ith_bit = (num>>i) & 1;
            if(ith_bit){
                if(crawler->right == NULL){
                    crawler->right = new TrieNode();
                }
                crawler = crawler->right;
            }else{
                if(crawler->left == NULL){
                    crawler->left = new TrieNode();
                }
                crawler = crawler->left;
            }
        }
    }
    int findMaxXor(TrieNode* root, int &num){
        int mx = 0;
        TrieNode* crawl = root;
        for(int i = 31; i>= 0 ;i--){
            int ith_bit = (num>>i) & 1;

            if(ith_bit == 1){
                if(crawl->left != NULL){
                    mx += pow(2, i);
                    crawl = crawl->left;
                }else{
                    crawl = crawl->right;
                }
            }else{
                if(crawl->right != NULL){
                    mx += pow(2, i);
                    crawl = crawl->right;
                }else{
                    crawl = crawl->left;
                }
            }
        }
        return mx;
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for(int &num: nums){
            insert(root, num);
        }
        int maxXor = 0;

        for(int i = 0; i<nums.size(); i++){
            int temp = findMaxXor(root, nums[i]);

            maxXor = max(maxXor, temp);
        }

        return maxXor;
    }
};
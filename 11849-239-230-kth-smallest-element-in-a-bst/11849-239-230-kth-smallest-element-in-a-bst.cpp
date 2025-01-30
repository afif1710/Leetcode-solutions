/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    priority_queue<int> pq;
    void insertOnPQ(TreeNode* root, int k){
        if(root==NULL){
            return;
        }
        insertOnPQ(root->left, k);
        pq.push(root->val);
        if(pq.size()>k){
            pq.pop();
        }
        insertOnPQ(root->right, k);

    }
    int kthSmallest(TreeNode* root, int k) {
        insertOnPQ(root, k);
        int tmp = pq.top();
        return tmp;
    }
};
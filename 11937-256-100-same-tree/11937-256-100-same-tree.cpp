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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p==NULL || q ==NULL){ //only one is NULL and another is not
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        bool f1 = isSameTree(p->left, q->left);  //Searching left nodes of both tree
        bool f2 = isSameTree(p->right, q->right);   //Searching right nodes of both tree

        return f1 && f2;
    }
};
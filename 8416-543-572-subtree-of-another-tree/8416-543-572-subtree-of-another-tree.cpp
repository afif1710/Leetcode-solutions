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

    bool sametree(TreeNode* r, TreeNode* s){
        if(!r && !s){
            return true;
        }
        if(r && !s || s && !r){
            return false;
        }
        if(r->val != s->val){
            return false;
        }

        return sametree(r->left, s->left) && sametree(r->right, s->right);



    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot){
            return true;
        }
        if(!root){
            return false;
        }
        if(sametree(root, subRoot)){
            return true;
        }
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};
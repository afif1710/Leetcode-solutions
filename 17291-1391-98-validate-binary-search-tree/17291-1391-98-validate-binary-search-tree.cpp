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
    vector<int>vc;
    void inOrder(TreeNode* root){
        if(root==NULL){
            return ;
        }
        inOrder(root->left);
        vc.push_back(root->val);
        inOrder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        int fg = 0;
        for(int i = 0; i<vc.size()-1; i++){
            if(vc[i] >= vc[i+1]){
                fg = 1;
                break;
            }
        }
        if (fg == 0)
            return (is_sorted(vc.begin(), vc.end()));
        else{
            return false;
        }
    }
};
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

    int rob(TreeNode* root) {
        vector<int> result = robHelper(root);
        return max(result[0], result[1]);
    }

    vector<int> robHelper(TreeNode* root) {
        if(root==NULL){
            return {0, 0};
        }
        vector<int> l = robHelper(root->left);
        vector<int> r = robHelper(root->right);
        vector<int>vc(2);
        vc[0] = root->val + l[1] + r[1];
        vc[1] = max(l[0], l[1]) + max(r[0], r[1]);

        return vc;
    }
    
    
};
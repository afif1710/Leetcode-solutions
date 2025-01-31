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
    int maxSum;
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);

        int take_subTree = l + r + root->val;
        int take_max_path = max(l, r) + root->val;
        int take_root = root->val;

        maxSum = max({maxSum, take_subTree, take_max_path, take_root});

        return max(take_max_path, take_root);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};
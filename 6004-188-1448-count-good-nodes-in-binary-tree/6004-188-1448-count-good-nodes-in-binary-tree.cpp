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
    int solve(TreeNode* root, int &count, int maxVal){
        if(root == NULL){
            return 0;
        }
        if(root->val >= maxVal){
            count++;
            maxVal = max(maxVal, root->val);
        }

        solve(root->left,count, maxVal);
        solve(root->right,count , maxVal);


        return count;

    }
    int goodNodes(TreeNode* root) {
        int maxVal = root->val;
        int count = 0;
        return solve(root, count, maxVal);
        
    }
};
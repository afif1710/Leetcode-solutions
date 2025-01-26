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

    void inOrder(TreeNode* root, vector<int> &vc){
        if(root == NULL){
            return;
        }
        inOrder(root->left, vc);
        vc.push_back(root->val);
        inOrder(root->right, vc);

    }

    int getMinimumDifference(TreeNode* root) {
        vector<int>vc;

        inOrder(root, vc);
        int i = 0, j = 1, n = vc.size();
        int diff = INT_MAX;
        while(j != n){
            diff = min(diff, vc[j] - vc[i]);
            i++;
            j++;
        }
        return diff;
    }
};
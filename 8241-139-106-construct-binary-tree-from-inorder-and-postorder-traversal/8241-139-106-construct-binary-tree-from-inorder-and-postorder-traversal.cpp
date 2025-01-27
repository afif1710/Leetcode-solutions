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

    TreeNode* construct(vector<int>& inorder, vector<int>& postorder, int start, int end, int &idx){
        if(start>end){
            return NULL;
        }
        int rootval = postorder[idx];
        int i = start;
        for(; i<end;i++){
            if(inorder[i] == rootval){
                break;
            }
        }

        idx--;
        TreeNode* root = new TreeNode(rootval);
        root->right = construct(inorder, postorder, i+1, end, idx);

        root->left = construct(inorder, postorder, start, i-1, idx);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int idx = n-1;
        return construct(inorder, postorder, 0, n-1, idx);
    }
};
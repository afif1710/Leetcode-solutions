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

    vector<int>res;
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL){
            return res;
        }   
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            TreeNode* tmp = NULL;
            while(n--){
                tmp = q.front();
                q.pop();
                if(tmp->left != NULL){
                    q.push(tmp->left);
                }
                if(tmp->right != NULL){
                    q.push(tmp->right);
                }
            }
            res.push_back(tmp->val);
        }
        return res;
    }
};

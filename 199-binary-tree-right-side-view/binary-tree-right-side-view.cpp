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
    void solveWithBFS(TreeNode* &root, vector<int> &res){
        
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* temp = NULL;
            int n = que.size();
            
            while(n--){
                temp = que.front();
                que.pop();
                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
            }
            res.push_back(temp->val);
         
        }

    }
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<int> res;
        solveWithBFS(root, res);
        return res;
    }
};
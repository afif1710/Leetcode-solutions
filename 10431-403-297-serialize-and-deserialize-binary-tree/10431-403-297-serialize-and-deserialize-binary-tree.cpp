/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void dfsSerialize(TreeNode* root, string &res){
        if(root==NULL){
            res.append("N,");
            return;
        }
        res.append(to_string(root->val) + ',');
        dfsSerialize(root->left, res);
        dfsSerialize(root->right, res);
    }
    string serialize(TreeNode* root) {
        string res = "";
        dfsSerialize(root, res);
        return res;
        
    }
    TreeNode* dfsDeserialize(vector<string> &vc, int &i){
        if(vc[i] == "N"){
            i++;
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(vc[i]));
        i++;
        root->left = dfsDeserialize(vc, i);
        root->right = dfsDeserialize(vc, i);

        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vc;
        stringstream ss(data);
        string token;

        // Split the string by comma
        while (getline(ss, token, ',')) {
            vc.push_back(token);
        }
        int i = 0;
        return dfsDeserialize(vc, i);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
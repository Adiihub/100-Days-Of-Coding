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
    vector<string> ans;
    void solve(TreeNode* root, string s){
        // Base
        if(!root) return;
        // Leaf Node
        if(root -> left == NULL && root -> right == NULL){
            // Leaf node ko bhi string me daal do
            s = s + to_string(root->val);
            ans.push_back(s);
            return;
        }

        // is node ko string me store kiya
        s = s+ to_string(root -> val);
        s = s + "->";
        // 12
        solve(root->left, s);
        solve(root->right, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear(); // ans me kuch vi ho to clear ho jaye
        string s =  "";
        solve(root, s);
        return ans;
    }
};
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
    bool solve(TreeNode* r1, TreeNode* r2){
    
        if(r1 == NULL && r2 == NULL)
            return true;
        if( !r1 || !r2 )
            return false;

        bool ans1 = solve(r1 -> left, r2-> right);
        bool ans2 = solve(r1 -> right, r2-> left);
        if(ans1 && ans2 && r1-> val == r2 -> val)
            return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return solve(root-> left, root -> right);
    }
};
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
    int Sum(TreeNode* root, string s){
        if(root == NULL) return 0;

        if(root -> left == NULL && root -> right == NULL){
            if(s == "left") return root -> val;
            return 0;
        }

        int lst = Sum(root -> left, "left");
        int rst = Sum(root -> right, "right");

        return lst + rst;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        string s = "";
        return Sum(root, s);
    }
};
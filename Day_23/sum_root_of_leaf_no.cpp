#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function to recursively calculate the sum of root-to-leaf numbers
    void solve(TreeNode* root, int sum, int &ans) {
        if (root == nullptr) return; // Base case: if node is null, return
        sum = sum * 10 + root->val; // Update the sum for the current path
        if (root->left == nullptr && root->right == nullptr) { // If leaf node
            ans += sum; // Add the path sum to the answer
        }
        solve(root->left, sum, ans); // Recur for left subtree
        solve(root->right, sum, ans); // Recur for right subtree
    }
    
    // Function to initiate the sum calculation
    int sumNumbers(TreeNode* root) {
        int ans = 0; // Initialize the answer to 0
        int sum = 0; // Initialize the sum for paths to 0
        solve(root, sum, ans); // Call the helper function
        return ans; // Return the final answer
    }
};

// Helper function to create a new tree node
TreeNode* newNode(int data) {
    TreeNode* node = new TreeNode(data);
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int main() {
    // Construct the binary tree
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    
    // Create an instance of Solution and call the sumNumbers function
    Solution sol;
    int result = sol.sumNumbers(root);
    
    // Print the result
    std::cout << "The sum of all numbers formed by root-to-leaf paths is: " << result << std::endl;
    
    return 0;
}

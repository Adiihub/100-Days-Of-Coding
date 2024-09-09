class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Step 1: Extract values from the linked list
        vector<int> values;
        ListNode* current = head;
        while (current) {
            values.push_back(current->val);
            current = current->next;
        }
        
        // Step 2: Initialize the matrix with -1
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        // Step 3: Fill the matrix in spiral order
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        int index = 0;
        
        while (top <= bottom && left <= right) {
            // Traverse from left to right
            for (int i = left; i <= right; ++i) {
                if (index < values.size()) {
                    matrix[top][i] = values[index++];
                }
            }
            ++top;
            
            // Traverse from top to bottom
            for (int i = top; i <= bottom; ++i) {
                if (index < values.size()) {
                    matrix[i][right] = values[index++];
                }
            }
            --right;
            
            // Traverse from right to left
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    if (index < values.size()) {
                        matrix[bottom][i] = values[index++];
                    }
                }
                --bottom;
            }
            
            // Traverse from bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    if (index < values.size()) {
                        matrix[i][left] = values[index++];
                    }
                }
                ++left;
            }
        }
        
        return matrix;
    }
};

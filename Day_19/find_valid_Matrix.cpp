class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int numRows = rowSum.size();
        int numCols = colSum.size();
        
        // Initialize the result matrix with 0s
        vector<vector<int>> matrix(numRows, vector<int>(numCols, 0));
        
        // Iterate over each cell in the matrix
        for(int i = 0; i < numRows; ++i) {
            for(int j = 0; j < numCols; ++j) {
                // The value to fill in the current cell is the minimum of the remaining row sum and column sum
                int value = min(rowSum[i], colSum[j]);
                
                // Fill the cell
                matrix[i][j] = value;
                
                // Subtract the value from both the row sum and column sum
                rowSum[i] -= value;
                colSum[j] -= value;
            }
        }
        
        return matrix;
    }
};

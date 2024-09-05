class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        
        int tsum = mean * (n + m);
        int gsum = 0;
        for (int roll : rolls) {
            gsum += roll;
        }
        
        // Calculate the sum of the missing rolls
        int missing_sum = tsum - gsum;
        
        // Check if it's possible to distribute this sum
        if (missing_sum < n || missing_sum > 6 * n) {
            return {};
        }
        
        // Result vector to store the missing rolls
        vector<int> result(n, missing_sum / n);
        int remainder = missing_sum % n;
        
        // Distribute the remainder across the first few elements
        for (int i = 0; i < remainder; ++i) {
            result[i]++;
        }
        
        return result;
    }
};

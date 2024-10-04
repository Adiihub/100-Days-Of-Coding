class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long totalSum = 0;

        for (int s : skill) {
            totalSum += s;
        }

        if (totalSum % (n / 2) != 0) {
            return -1;
        }

        long long targetSum = totalSum / (n / 2); // Target sum for each team
        long long totalChemistry = 0;

        sort(skill.begin(), skill.end());

        for (int i = 0; i < n / 2; i++) {
            int left = skill[i];
            int right = skill[n - i - 1];

            if (left + right != targetSum) {
                return -1;
            }

            totalChemistry += (long long)left * right;
        }

        return totalChemistry;
    }
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i < 10; i++) {
            dfs(i, n, ans);
        }
        return ans;
    }

    void dfs(int current, int n, vector<int>& ans) {
        if (current > n) return;
        ans.push_back(current);
        for (int i = 0; i < 10; i++) {
            if (current * 10 + i > n) return;
            dfs(current * 10 + i, n, ans);
        }
    }
};

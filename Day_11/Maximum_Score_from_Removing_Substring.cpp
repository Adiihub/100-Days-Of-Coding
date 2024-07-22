class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }
        
        int points = 0;
        stack<char> st;

        // First pass: prioritize removing "ab"
        for (char c : s) {
            if (!st.empty() && st.top() == 'a' && c == 'b') {
                st.pop();
                points += x;
            } else {
                st.push(c);
            }
        }

        // Second pass: handle remaining characters for "ba"
        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

        for (char c : remaining) {
            if (!st.empty() && st.top() == 'b' && c == 'a') {
                st.pop();
                points += y;
            } else {
                st.push(c);
            }
        }

        return points;
    }
};

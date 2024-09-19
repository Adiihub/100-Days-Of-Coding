class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        if (isdigit(expression[0])) {
            bool isNumber = true;
            for (char c : expression) {
                if (!isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }
            if (isNumber) {
                return {stoi(expression)};
            }
        }

        vector<int> result;
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> leftResults = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightResults = diffWaysToCompute(expression.substr(i + 1));
                
                for (int left : leftResults) {
                    for (int right : rightResults) {
                        if (c == '+') {
                            result.push_back(left + right);
                        } else if (c == '-') {
                            result.push_back(left - right);
                        } else if (c == '*') {
                            result.push_back(left * right);
                        }
                    }
                }
            }
        }

        return result;
    }
};

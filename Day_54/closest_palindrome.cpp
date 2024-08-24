class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        
        if (len == 1) {
            return to_string(stoi(n) - 1);
        }

        vector<long> candidates;

        candidates.push_back((long)pow(10, len - 1) - 1);

        candidates.push_back((long)pow(10, len) + 1);

        // Get the first half of the number
        long prefix = stol(n.substr(0, (len + 1) / 2));
        // Generate palindromes by reflecting the prefix
        candidates.push_back(createPalindrome(prefix, len % 2 == 0));
        candidates.push_back(createPalindrome(prefix - 1, len % 2 == 0));
        candidates.push_back(createPalindrome(prefix + 1, len % 2 == 0));

        // Determine the closest palindrome
        long originalNum = stol(n);
        long closestPalindrome = -1;
        long minDiff = LONG_MAX;

        for (long candidate : candidates) {
            if (candidate == originalNum) continue;
            long diff = abs(candidate - originalNum);

            if (diff < minDiff || (diff == minDiff && candidate < closestPalindrome)) {
                minDiff = diff;
                closestPalindrome = candidate;
            }
        }

        return to_string(closestPalindrome);
    }

private:
    long createPalindrome(long prefix, bool isEven) {
        string s = to_string(prefix);
        string rev(s.rbegin(), s.rend());

        if (isEven) {
            return stol(s + rev);
        } else {
            return stol(s + rev.substr(1));
        }
    }
};
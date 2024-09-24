class TrieNode {
public:
    TrieNode* children[10];
    TrieNode() {
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
    }
};

class Solution {
public:
    void insert(TrieNode* root, const string& number) {
        TrieNode* node = root;
        for (char digit : number) {
            int idx = digit - '0';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
    }

    int findLongestCommonPrefix(TrieNode* root, const string& number) {
        TrieNode* node = root;
        int commonPrefixLength = 0;
        for (char digit : number) {
            int idx = digit - '0';
            if (!node->children[idx]) {
                break;
            }
            node = node->children[idx];
            commonPrefixLength++;
        }
        return commonPrefixLength;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode();
        for (int x : arr1) {
            insert(root, to_string(x));
        }

        int maxLength = 0;

        for (int y : arr2) {
            int prefixLength = findLongestCommonPrefix(root, to_string(y));
            maxLength = max(maxLength, prefixLength);
        }

        return maxLength;
    }
};

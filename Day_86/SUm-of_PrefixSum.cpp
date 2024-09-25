#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int count;
    
    TrieNode() : count(0) {}
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a word into the Trie and increase the count for each prefix.
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
            node->count++;
        }
    }
    
    // For a given word, calculate the sum of counts for all prefixes.
    int getPrefixScore(const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char ch : word) {
            if (node->children.count(ch)) {
                node = node->children[ch];
                score += node->count;
            } else {
                break;
            }
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        vector<int> result;
        
        // Insert all words into the Trie
        for (const string& word : words) {
            trie.insert(word);
        }
        
        // Calculate the prefix score for each word
        for (const string& word : words) {
            result.push_back(trie.getPrefixScore(word));
        }
        
        return result;
    }
};

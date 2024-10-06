class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Split the sentences into words
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);

        int i = 0; // pointer for the beginning of the sentences
        int j = 0; // pointer for the end of the sentences

        // Compare words from the start
        while (i < words1.size() && i < words2.size() && words1[i] == words2[i]) {
            i++;
        }

        // Compare words from the end
        while (j < words1.size() && j < words2.size() && words1[words1.size() - 1 - j] == words2[words2.size() - 1 - j]) {
            j++;
        }

        // If i + j covers the entirety of one of the sentences, return true
        return (i + j >= words1.size() || i + j >= words2.size());
    }

private:
    // Helper function to split a string into words
    vector<string> split(string &s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }
};

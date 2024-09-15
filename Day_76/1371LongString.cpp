class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mask_to_index;
        mask_to_index[0] = -1;
        
        int mask = 0;  
        int max_len = 0;  

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'a') mask ^= (1 << 0);
            else if (s[i] == 'e') mask ^= (1 << 1);
            else if (s[i] == 'i') mask ^= (1 << 2);
            else if (s[i] == 'o') mask ^= (1 << 3);
            else if (s[i] == 'u') mask ^= (1 << 4);

            if (mask_to_index.find(mask) != mask_to_index.end()) {
                max_len = max(max_len, i - mask_to_index[mask]);
            } else {
                mask_to_index[mask] = i;
            }
        }

        return max_len;
    }
};

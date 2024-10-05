class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if (len1 > len2) return false;

        vector<int> s1map(26, 0), s2map(26, 0);
        
        for (int i = 0; i < len1; i++) {
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }

        for (int i = 0; i < len2 - len1; i++) {
            if (s1map == s2map) return true;

            s2map[s2[i] - 'a']--;         
            s2map[s2[i + len1] - 'a']++;    
        }

        return s1map == s2map;
    }
};

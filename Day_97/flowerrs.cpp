class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int length = fb.size();
        
        for (int i = 0; i < length; i++) {
            if (fb[i] == 0 && (i == 0 || fb[i - 1] == 0) && (i == length - 1 || fb[i + 1] == 0)) {
                fb[i] = 1;
                n--;      
                if (n <= 0) return true; 
                i++;  
            }
        }
        
        return n <= 0;  
    }
};

class Solution {
public:
    int passThePillow(int n, int time) {
        int position = 1;
        int direction = 1; // 1 for forward, -1 for backward

        for (int i = 0; i < time; ++i) {
            position += direction;
            if (position == n) {
                direction = -1;
            } else if (position == 1) {
                direction = 1;
            }
        }

        return position;
    }
};

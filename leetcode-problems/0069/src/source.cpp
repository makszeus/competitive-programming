class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;

        unsigned int a = 1;
        unsigned int b = x / 2 + 1;

        while (a <= b) {
            unsigned int mid = a + (b - a) / 2;

            if (mid > x / mid) {
                b = mid - 1;
            } else {
                a = mid + 1;
            }
        }

        return b;
    }
};
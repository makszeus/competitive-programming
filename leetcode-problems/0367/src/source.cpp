class Solution {
public:
    bool isPerfectSquare(int num) {
        long long a = 1, b = num;
        while (a <= b) {
            long long mid = a + (b - a) / 2;
            long long square = mid * mid;
            if (square == num) {
                return true;
            } else if (square > num) {
                b = mid - 1;
            } else {
                a = mid + 1;
            }
        }
        return false;
    }
};
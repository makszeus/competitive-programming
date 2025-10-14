class Solution {
public:
    bool judgeSquareSum(int c) {
    for (long long int i = 0; i * i <= c; i++) {
        long long int j = c - i * i;
        if (isPerfectSquare(j)) {
            return true;
        }
    }
    return false;
    }
private:
    bool isPerfectSquare(int n) {
        int s = sqrt(n);
        return s * s == n;
    }
};

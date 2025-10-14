class Solution {
public:
    long long coloredCells(int n) {
        if (n == 1) {
            return 1;
        }

        long long k = 4, ans = 1;

        for (int i = 1; i < n; ++i) {
            ans += k; k += 4;
        }

        return ans;
    }
};
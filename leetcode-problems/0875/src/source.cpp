class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = ranges::max(piles);

        while (l < r) {
            const int m = (l + r) / 2;
            if (hrs(piles, m) <= h) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }

private:
    int hrs(const vector<int>& piles, int m) {
        int total = 0;
        for (const auto& pile : piles) {
            total += (pile - 1) / m + 1;
        }
        return total;
    }
};
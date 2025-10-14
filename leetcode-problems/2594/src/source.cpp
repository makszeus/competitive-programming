class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long l = 1, r = static_cast<long>(std::ranges::min(ranks)) * cars * cars;
        while (l < r) {
            const long m = (l + r) / 2 ;
            if (num_of_cars(ranks, m) >= cars) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
private:
    long num_of_cars(vector<int>& rank_s, long time) {
        long ans = 0;
        for (const auto &i : rank_s) {
            ans += sqrt(time / i);
        }
        return ans;
    }
};
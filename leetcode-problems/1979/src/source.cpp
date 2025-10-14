class Solution {
public:
    int findGCD(vector<int>& nums) {
        size_t min_ = nums[0], max_ = nums[0];

        for (const auto &i : nums) {

            if (i < min_) min_ = i;
            if (i > max_) max_ = i;

        }

        // return std::gcd(min_, max_);

        while (max_ != 0) {
            int temp = max_;
            max_ = min_ % max_;
            min_ = temp;
        }

        return min_;

    }
};

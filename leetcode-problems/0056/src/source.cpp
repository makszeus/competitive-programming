class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return {};

        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
            return a[0] < b[0];
        });

        std::vector<std::vector<int>> merged;
        std::vector<int> current_interval = intervals[0];

        for (size_t i = 1; i < intervals.size(); ++i) {
            if (current_interval[1] >= intervals[i][0]) {
                current_interval[1] = std::max(current_interval[1], intervals[i][1]);
            } else {
                merged.push_back(current_interval);
                current_interval = intervals[i];
            }
        }

        merged.push_back(current_interval);
        return merged;
    }
};

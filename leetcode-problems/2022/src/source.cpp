#include <vector>
#include <utility>

class Solution {
public:
    std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n) {
        std::vector<std::vector<int>> ans;

        if (original.size() != m * n) {
            return ans;
        }

        ans.resize(m, std::vector<int>(n));

        size_t index = 0;
        for (size_t i = 0; i < m; ++i) {
            std::move(original.begin() + index, original.begin() + index + n, ans[i].begin());
            index += n;
        }

        return ans;
    }
};

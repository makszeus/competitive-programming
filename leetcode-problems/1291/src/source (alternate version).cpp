class Solution {
public:
    static std::vector<int> sequentialDigits(int low, int high) {
        std::vector<int> allSeqNums;
        for (size_t digitStart = 1; digitStart <= 9; ++digitStart) {
            int num = 0;
            for (size_t digit = digitStart; digit <= 9; ++digit) {
                num = num * 10 + (int)digit;
                allSeqNums.push_back(num);
            }
        }

        std::vector<int> ans;
        
        for (const auto &num : allSeqNums) {
            if (num >= low && num <= high) {
                ans.push_back(num);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

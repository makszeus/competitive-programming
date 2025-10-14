class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector <int> ans; size_t k = 0;
        for (const auto &i : nums) {
            if (i == pivot) {
                k++;
            } else if (i < pivot) {
                ans.push_back(i);
            }
        }
        for (size_t i = 0; i < k; ++i) {
            ans.push_back(pivot);
        }
        for (const auto &i : nums) {
            if (i > pivot) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
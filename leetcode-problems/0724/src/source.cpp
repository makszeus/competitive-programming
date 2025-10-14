class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefix = 0;
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        for (size_t i = 0; i < nums.size(); ++i) {
            sum -= nums[i];
            if (prefix == sum) return i;
            prefix += nums[i];
        }
        return -1;
    }
};
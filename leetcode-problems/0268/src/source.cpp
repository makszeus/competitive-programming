class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // return (nums.size() + 1) * nums.size() / 2 - std::accumulate(nums.begin(), nums.end(), 0.0);
        // x ^ x = 0, x ^ 0 = x.
        int x = nums.size();
        for (size_t i = 0; i < nums.size(); ++i) {
            x = x ^ i ^ nums[i];
        }
        return x;
    }
};
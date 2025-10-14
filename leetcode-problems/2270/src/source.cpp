class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        std::vector <long long int> p(nums.size());
        long long int ans = 0;
        p[0] = nums[0];
        for (long long int i = 1; i < nums.size(); ++i) {
            p[i] = p[i - 1] + nums[i];
        }
        for (long long int i = 0; i < nums.size() - 1; ++i) {
            if (p[i] >= p[nums.size() - 1] - p[i]) {
                ans++;
            }
        }
        return ans;
    }
};
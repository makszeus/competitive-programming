class Solution {
    public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        
        int max_idx = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[max_idx]) {
                max_idx = i;
            }
        }
        
        vector<int> result;
        int idx = max_idx;
        while (idx != -1) {
            result.push_back(nums[idx]);
            idx = prev[idx];
        }
        
        return result;
    }

};

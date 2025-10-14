class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCnt = 0, ans = 0;
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                zeroCnt++;
            }
            while (zeroCnt > 1) {
                if (nums[left] == 0) {
                    zeroCnt--;
                }
                left++;
            }
            ans = std::max(ans, right - left);
            right++;
        }
        return ans;
    }
};
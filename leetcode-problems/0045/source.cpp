class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, ans = 0, end = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            l = max(l, i + nums[i]);
            if (l >= nums.size() - 1) {
                ++ans; break;
            }
            if (i == end) {
                end = l;
                ans++;
            }
        }
        return ans;
    }
};
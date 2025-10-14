class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = ranges::min(nums), r = ranges::max(nums);
        while (l < r) {
            const int m = (l + r) / 2;
            if (numOfStolenHouses(nums, m) >= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
private:
    int numOfStolenHouses(const vector<int>& nums, int capacity) {
        int st_h = 0;
        for (int i = 0; i < nums.size(); ++i)
        if (nums[i] <= capacity) {
            ++st_h;
            ++i;
        }
        return st_h;
    }
};
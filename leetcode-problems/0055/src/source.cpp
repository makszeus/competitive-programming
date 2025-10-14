class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ind = 0, i = 0;
        while (ind < nums.size() - 1 && i < nums.size() - 1) {
            ind = std::max(i + nums[i], ind);
            if (i == ind && nums[i] == 0) {
                return false;
            }
            i++;
        }
        return true;
    }
};
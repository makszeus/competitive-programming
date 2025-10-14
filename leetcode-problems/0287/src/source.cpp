class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        size_t len = nums.size();
        for (const auto &i : nums) {

            size_t ind = abs(i);
            if (nums[ind] < 0) {

                return ind;

            }

            nums[ind] = -nums[ind];

        }

        return -1;

    }
};

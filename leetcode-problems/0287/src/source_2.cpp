class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        size_t slow = 0, fast = 0;
        for (;;) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }

        slow = 0;
        while (slow != fast) {
            slow = nums[slow]; fast = nums[fast];
        }

        return slow;

    }
};

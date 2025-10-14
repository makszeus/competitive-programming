class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();

        // Handle cases where division into arrays of size 3 is not possible
        if (n % 3 != 0) {
            return {};
        }

        // Sort the array to facilitate grouping
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        // Iterate through the array in groups of 3
        for (int i = 0; i < n; i += 3) {
            vector<int> subarray = {nums[i], nums[i + 1], nums[i + 2]};

            // Check if the difference between the largest and smallest elements is within the allowed range
            if (subarray[2] - subarray[0] <= k) {
                result.push_back(subarray);
            } else {
                // If not, it's not possible to divide the array
                return {};
            }
        }

        return result;
    }
};

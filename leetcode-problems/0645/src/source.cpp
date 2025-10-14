class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        size_t len = nums.size(); int ind;
        int sz = std::accumulate (nums.begin(), nums.end(), 0);
        int zs = (len + 1) * len / 2;

        nums.push_back(len + 1);

        for (const auto &i : nums) {
            ind = abs(i);
            if (nums[ind] < 0) break;
            nums[ind] = -nums[ind];
        }

        return {ind, ind + (zs - sz)};

    }
};

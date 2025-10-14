class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        std::vector <std::vector<int>> ans;
        size_t k = 0, t = 0;
        while (k != nums1.size() && t != nums2.size()) {
            if (nums1[k][0] == nums2[t][0]) {
                ans.push_back({nums1[k][0], nums1[k][1] + nums2[t][1]});
                k++; t++;
            } else if (nums1[k][0] > nums2[t][0]) {
                ans.push_back({nums2[t][0], nums2[t][1]}); t++;
            } else {
                ans.push_back({nums1[k][0], nums1[k][1]}); k++;
            }
        }

        while (k < nums1.size()) {
            ans.push_back({nums1[k][0], nums1[k][1]});
            k++;
        }

        while (t < nums2.size()) {
            ans.push_back({nums2[t][0], nums2[t][1]});
            t++;
        }

        return ans;
    }
};
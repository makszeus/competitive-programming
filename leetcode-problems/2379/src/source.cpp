class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = 0;
        for (size_t i = 0; i < k; ++i) {
            if (blocks[i] == 'W') {
                ans++;
            }
        }
        int ind = k, ans_r = ans;
        while (ind != (int)blocks.size()) {
            if (blocks[ind - k] == 'W') {
                ans_r--;
            }
            if (blocks[ind] == 'W') {
                ans_r++;
            }
            ans = std::min(ans, ans_r);
            ind++;
        }
        return ans;
    }
};
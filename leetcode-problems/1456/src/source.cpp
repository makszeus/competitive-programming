class Solution {
public:
    int maxVowels(string s, int k) {
        std::unordered_map <char, int> x = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};
        int ans = 0, ind = k;
        for (size_t i = 0; i < k; ++i) {
            if (x[s[i]] == 1) {
                ans++;
            }
        }
        int ans_r = ans;
        while (ind != s.size()) {
            if (x[s[ind - k]] == 1) {
                ans_r--;
            }
            if (x[s[ind]] == 1) {
                ans_r++;
            }
            ans = std::max(ans, ans_r);
            ind++;
        }
        return ans;
    }
};
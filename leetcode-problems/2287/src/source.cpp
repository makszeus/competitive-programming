class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        std::unordered_map <char, int> x;
        for (const auto &i : s) {
            x[i]++;
        }

        int ans = 0, i = 0;

        for (;;) {
            if (x[target[i]] == 0) {
                break;
            } else {
                x[target[i]]--;
                i++;
            }
            if (i == target.size()) {
                i = 0; ans++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, ans = 0;
        std::vector <int> v(3, 0);
        int n = s.size();

        for (size_t i = 0; i < n; ++i) {
            v[s[i] - 'a']++;
            while (v[0] > 0 && v[1] > 0 && v[2] > 0) {
                ans += n - i;
                v[s[left] - 'a']--;
                left++;
            }

        }
        return ans;
    }
};
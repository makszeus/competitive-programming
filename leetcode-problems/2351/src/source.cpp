class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.length();

        std::vector<int> freq(26, 0);

        for (int i = 0; i < n; ++i) {
            freq[s[i] - 'a']++;
            if (freq[s[i] - 'a'] == 2) {
                return s[i];
            }
        }

        return s[0];
    }
};
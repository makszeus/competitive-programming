class Solution {
public:
    int percentageLetter(string s, char letter) {
        size_t sx = 0;
        for (const auto &i : s) {
            if (i == letter) ++sx;
        }
        return (double)sx / s.length() * 100;
    }
};

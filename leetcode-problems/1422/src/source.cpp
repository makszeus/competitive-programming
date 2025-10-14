class Solution {
public:
    int maxScore(std::string s) {
        int n = s.length();
        int zeros = 0, ones = 0;

        for (char c : s) {
            if (c == '1') ones++;
        }

        int maxScore = 0;
        int leftZeros = 0, rightOnes = ones;

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '0') {
                leftZeros++;
            } else {
                rightOnes--;
            }
            maxScore = std::max(maxScore, leftZeros + rightOnes);
        }

        return maxScore;
    }
};

class Solution {
public:
    bool areAlmostEqual(std::string s1, std::string s2) {
        int count = 0;
        char s1Char1, s1Char2, s2Char1, s2Char2;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                count++;
                if (count > 2) {
                    return false;
                }
                if (count == 1) {
                    s1Char1 = s1[i];
                    s2Char1 = s2[i];
                } else {
                    s1Char2 = s1[i];
                    s2Char2 = s2[i];
                }
            }
        }

        return (count == 0 || (count == 2 && s1Char1 == s2Char2 && s1Char2 == s2Char1));
    }

};

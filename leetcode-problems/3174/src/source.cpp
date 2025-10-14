class Solution {
public:
    string clearDigits(string s) {
        int ansInd = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                ansInd--;
            } else {
                s[ansInd++] = s[i];
            }
        }
        s.resize(ansInd);
        return s;
    }
};
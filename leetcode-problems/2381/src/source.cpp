class Solution {
public:
    string shiftingLetters(string str, vector<vector<int>>& operations) {
        int currentShift = 0;
        vector<int> shiftTimeline(str.length() + 1, 0);

        for (const auto& operation : operations) {
            int startIdx = operation[0];
            int endIdx = operation[1];
            int shiftDirection = operation[2];
            int change = shiftDirection ? 1 : -1;
            shiftTimeline[startIdx] += change;
            shiftTimeline[endIdx + 1] -= change;
        }

        for (int i = 0; i < str.length(); ++i) {
            currentShift = (currentShift + shiftTimeline[i]) % 26;
            int newCharIndex = (str[i] - 'a' + currentShift + 26) % 26;
            str[i] = 'a' + newCharIndex;
        }

        return str;
    }
};

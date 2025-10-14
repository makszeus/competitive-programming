class Solution {
public:
    string addStrings(string num1, string num2) {
        std::string result;
        int i = static_cast<int>(num1.size() - 1), j = static_cast<int>(num2.size() - 1), ost = 0;

        while (i >= 0 or j >= 0 or ost) {
            const int dig_1 = (i >= 0) ? num1[i] - '0' : 0;
            const int dig_2 = (j >= 0) ? num2[j] - '0' : 0;
            const int sum = dig_1 + dig_2 + ost;

            result.push_back(static_cast<char>((sum % 10) + '0'));
            ost = sum / 10;

            i--; j--;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
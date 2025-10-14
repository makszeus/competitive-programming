class Solution {
public:
    int calculate(string s) {
        int ans = 0, num = 0, prev;
        char sign = '+';
        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if (!isdigit(c) && !iswspace(c) || i == s.size() - 1) {
                if (sign == '+' or sign == '-') {
                    prev = (sign == '+') ? num : -num;
                } else if (sign == '*' or sign == '/') {
                    ans = ans - prev;
                    prev = (sign == '*') ? prev * num : prev / num;
                }
                ans += prev;
                sign = c; num = 0;
            }
        }

        return ans;
    }
};
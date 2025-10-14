class Solution {
public:
    int calculate(string s) {
        int ans = 0, num = 0;
        char sign = '+';
        std::stack <int> x;
        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if (!isdigit(c) && !iswspace(c) || i == s.size() - 1) {
                if (sign == '+') {
                    x.push(num);
                } else if (sign == '-') {
                    x.push(-num);
                } else if (sign == '*') {
                    int tmp = x.top(); x.pop();
                    x.push(tmp * num);
                } else if (sign == '/') {
                    int tmp = x.top(); x.pop();
                    x.push(tmp / num);
                }
                sign = c; num = 0;
            }
        }

        while (!x.empty()) {
            ans += x.top();
            x.pop();
        }

        return ans;
    }
};
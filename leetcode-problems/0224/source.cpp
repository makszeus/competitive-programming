class Solution {
public:
    int calculate(string s) {
        int ans = 0, num = 0, sign = 1; 
        std::stack<std::pair<int, int>> st;
        
        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else {
                ans += sign * num;
                num = 0;
                
                if (c == '+') {
                    sign = 1;
                } else if (c == '-') {
                    sign = -1;
                } else if (c == '(') {
                    st.push({ans, sign});
                    ans = 0;
                    sign = 1; 
                } else if (c == ')') {
                    ans = st.top().first + st.top().second * ans;
                    st.pop();
                }
            }
        }
        return ans + sign * num;
    }
};
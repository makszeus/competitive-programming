class Solution {
public:
    int clumsy(int n) {
        int ans = 0, cnt = -1, tmp = n; n--;
        while (n > 0) {
            cnt++;
            if (cnt == 0) {
                tmp *= n;
            } else if (cnt == 1) {
                tmp /= n;
            } else if (cnt == 2) {
                tmp += n;
                ans += tmp; n--; tmp = -n; cnt = -1;
            }
            n--;
        }
        if (cnt != 2) {
            ans += tmp;
        }
        return ans;
    }
};
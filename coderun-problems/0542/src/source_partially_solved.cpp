#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n < 3) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::sort(a.begin(), a.end());

    long long suff = 0, pref = 0;
    long long ans = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        suff += a[n - 1] - a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        suff -= (a[n - 1] - a[i]);
        ans = std::min(ans, suff + pref);
        pref += static_cast<long long>(a[i + 1] - a[i]) * (i + 1);
    }

    std::cout << ans << std::endl;

    return 0;
}

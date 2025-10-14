#include <iostream>
#include <limits>
#include <vector>

typedef long long ll;

#define pb push_back
#define FIO std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

void solve() {

    ll n, k;
    std::cin >> n >> k;

    std::vector<ll> arr(n);
    for (ll i = 0; i < n; ++i) std::cin >> arr[i];


    for (auto el:arr) {
        if (el % k == 0) {
            std::cout << 0 << std::endl;
            return;
        }
    }

    if (k==2 || k==3 || k==5) {

        ll min_ = 1e9;
        for (auto x:arr) min_ = std::min(min_, k * ((x + k) / k) - x);
        std::cout << min_ << std::endl;

    }
    else {

        ll mn = 1e9;
        for (auto el : arr) {
            mn = std::min(mn, k * ((el + k - 1) / k) - el);
        }

        std::vector <ll> diff2;
        for (auto el:arr) diff2.pb(2 * ((el + 1) / 2) - el);

        sort(diff2.begin(),diff2.end());
        std::cout << std::min(mn, diff2[0] + diff2[1]) << std::endl;

    }
}

int main() {
    FIO
    ll tt; std::cin >> tt;
    for(size_t i = 1; i <= tt; ++i) {
        solve();
    }

    return 0;
}

#include <iostream>
#include <limits>
#include <vector>

#define FIO std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

void solve() {

    int pin, operations = 0, cnt = 1; std::cin >> pin;
    int digits[4] = {10, 10, 10, 10}; size_t ind = 0;
    while (pin > 0) {
        digits[ind] = (pin % 10 == 0) ? 10 : pin % 10; pin /= 10; ind++;
    }
    for (int i = 3; i >= 0; --i) {
        operations += abs(digits[i] - cnt) + 1; cnt = digits[i];
    }

    std::cout << operations << std::endl;
}

int main() {

    FIO
    size_t tt; std::cin >> tt;
    for(size_t i = 1; i <= tt; ++i) {
        solve();
    }

    return 0;
}

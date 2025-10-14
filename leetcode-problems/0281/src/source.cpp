#include <iostream>
#include <vector>

int main() {
    const std::vector v = {-4, 2, 6, -7, 1, 5};
    const std::vector z = {10, -3, 4, -8, 0, 7, 2, 11, -5};
    std::vector<int> final;
    int a = 0, b = 0;

    final.reserve(v.size() + z.size());

    while (a < v.size() and b < z.size()) {
        final.push_back(v[a++]);
        final.push_back(z[b++]);
    }

    while (a < v.size()) {
        final.push_back(v[a++]);
    }

    while (b < z.size()) {
        final.push_back(z[b++]);
    }

    for (const auto &i : final) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}

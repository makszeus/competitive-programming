#include <iostream>

bool canFormPalindrome(const std::string& s, const size_t &n, const size_t &k) {

    int freq[26] = {0};
    for (char c : s) {
        freq[c - 'a']++;
    }
    int oddCount = 0;
    for (int i : freq) {
        if (i % 2 != 0) {
            oddCount++;
        }
    }
    if ((n % 2 == 0) && (n - k == 1) or (oddCount - k == 1)) return true;
    return (n % 2 == 0) ? k >= oddCount : k >= oddCount - 1;
}

int main() {

    size_t T; std::cin >> T;
    for (size_t i = 0; i < T; ++i) {
        size_t n, k; std::string s; std::cin >> n >> k >> s;
        std::cout << (canFormPalindrome(s, n, k) ? "YES\n" : "NO\n");
    }

    return 0;
}

#include <iostream>

bool isOneEditDistance (const std::string &s, const std::string &t) {
    if (s.length() > t.length()) {
        return isOneEditDistance(t, s);
    }
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] != t[i]) {
            if (s.length() == t.length()) {
                return s.substr(i + 1) == t.substr(i + 1);
            }
            return s.substr(i) == t.substr(i + 1);
        }
    }
    return s.length() + 1 == t.length();
}

int main() {
    std::cout << isOneEditDistance("hell", "hello") << std::endl;
    return 0;
}

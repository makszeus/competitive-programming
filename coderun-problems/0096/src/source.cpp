#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() 
{

    size_t n, k; std::cin >> n >> k;
    std::string s; std::cin >> s;

    std::unordered_map <char, size_t> x;

    size_t a = 0, b = 0, l = 0, pos = 0;
    while (b != s.length()) {

        if (x[s[b]] == k) {
            --x[s[a]]; ++a;
        }
        else if (b - a + 1 > l) {
            l = b - a + 1;
            pos = a + 1;
        }
        else {
            ++x[s[b]];
            ++b;    
        }
        
    }

    std::cout << l << " " << pos;
        
	return 0;
}

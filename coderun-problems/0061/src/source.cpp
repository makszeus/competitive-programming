#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>

int main() {
    
    std::unordered_set<int> set1;
    std::vector<int> result;
    std::string line1, line2;

    std::getline(std::cin, line1);
    std::getline(std::cin, line2);

    std::istringstream iss1(line1);
    int number;
    while (iss1 >> number) {
        set1.insert(number);
    }

    std::istringstream iss2(line2);
    while (iss2 >> number) {
        if (set1.find(number) != set1.end()) {
            result.push_back(number);
        }
    }

    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());

    for (int num : result) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    return 0;
}

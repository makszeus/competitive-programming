#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    
    std::set<int> set_A;
    std::set<int> set_B;

    int color;
    for (int i = 0; i < N; ++i) {
        std::cin >> color;
        set_A.insert(color);
    }

    for (int i = 0; i < M; ++i) {
        std::cin >> color;
        set_B.insert(color);
    }

    std::vector<int> common_colors;
    std::set_intersection(set_A.begin(), set_A.end(), set_B.begin(), set_B.end(),
                          std::back_inserter(common_colors));

    std::vector<int> only_A;
    std::set_difference(set_A.begin(), set_A.end(), set_B.begin(), set_B.end(),
                        std::back_inserter(only_A));

    std::vector<int> only_B;
    std::set_difference(set_B.begin(), set_B.end(), set_A.begin(), set_A.end(),
                        std::back_inserter(only_B));

    std::cout << common_colors.size() << std::endl;
    for (int color : common_colors) {
        std::cout << color << " ";
    }
    std::cout << std::endl;

    std::cout << only_A.size() << std::endl;
    for (int color : only_A) {
        std::cout << color << " ";
    }
    std::cout << std::endl;

    std::cout << only_B.size() << std::endl;
    for (int color : only_B) {
        std::cout << color << " ";
    }
    std::cout << std::endl;

    return 0;
}

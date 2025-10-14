#include <iostream>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};

bool isReflected(std::vector<std::pair<int, int>>& points) {
    std::unordered_set<std::pair<int, int>, pair_hash> pointSet;
    int minX = INT_MAX, maxX = INT_MIN;

    for (const auto& p : points) {
        pointSet.insert(p);
        minX = std::min(minX, p.first);
        maxX = std::max(maxX, p.first);
    }

    int line = maxX + minX;
    for (const auto&[fst, snd] : points) {
        if (!pointSet.contains({line - fst, snd})) {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<std::pair<int, int>> points1 = {{1, 2}, {3, 2}, {5, 2}};
    if (isReflected(points1)) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "Not OK." << std::endl;
    }
    return 0;
}
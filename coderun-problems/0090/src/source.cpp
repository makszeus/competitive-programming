#include <iostream>
#include <string>
#include <vector>

int main() 
{
    std::vector <int> vec1, vec2;
    int N, M, a, b, x, y;

    std::cin >> N;
    for (size_t i = 0; i < N; ++i) {
        std::cin >> a; vec1.push_back(a);
    }
    std::cin >> M;
    for (size_t i = 0; i < M; ++i) {
        std::cin >> a; vec2.push_back(a);
    }

    int diff = std::abs(vec1[0] - vec2[0]);
    a = 0, b = 0;

    while (a < N && b < M) {

        if (std::abs(vec1[a] - vec2[b]) < diff) {
            diff = std::abs(vec1[a] - vec2[b]);
            x = a; y = b;
        }
        if (vec1[a] < vec2[b]) {
            ++a;
        }
        else {
            ++b;
        }
        
    }

    std::cout << vec1[x] << " " << vec2[y];
    
	return 0;
}

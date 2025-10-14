#include <iostream>
#include <vector>

int main() {

    size_t N, K;
    std::cin >> N >> K;
    
    std::vector<size_t> numbers(N);
    for (size_t i = 0; i < N; ++i) {
        std::cin >> numbers[i];
    }

    size_t left = 0;
    size_t current_sum = 0;
    size_t ans = 0;

    for (size_t right = 0; right < N; ++right) {
        current_sum += numbers[right];

        while (current_sum > K && left <= right) {
            current_sum -= numbers[left++];
        }

        if (current_sum == K) {
            ++ans;
        }
    }

    std::cout << ans;

    return 0;
}

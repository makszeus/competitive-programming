#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using int64 = long long;
using i128 = __int128_t;

i128 igcd(i128 a, i128 b){
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    while (b) {
        i128 t = a % b; a = b; b = t;
    }
    return a;
}
std::string toString(i128 x) {
    if (x == 0) {
        return "0";
    }
    bool neg = x < 0;
    if (neg) {
        x = -x;
    }
    std::string s;
    while(x) {
        int d = (int)(x % 10);
        s.push_back(char('0' + d));
        x /= 10;
    }
    if (neg) {
        s.push_back('-');
    }
    std::reverse(s.begin(), s.end());
    return s;
}

int main() {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;
    
    std::vector<int> f(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> f[i]; --f[i];
    }

    std::vector<int> visited(n, -1);
    std::vector<int> cycleLength(n, 0);

    for (int i = 0; i < n; ++i) {
        int v = i;
        while (visited[v] == -1){
            visited[v] = i;
            v = f[v];
        }
        if (visited[v] == i) {
            int u = v, len = 1;
            u = f[u];
            while (u != v) {
                ++len;
                u = f[u];
            }
            u = v;
            for (int t = 0; t < len; ++t) {
                cycleLength[u] = len;
                u = f[u];
            }
        }
    }

    std::vector<int> dist(n, -1);
    std::function<int(int)> dfs = [&](int u)->int{
        if (cycleLength[u] > 0) return dist[u] = 0;
        if (dist[u] != -1) return dist[u];
        return dist[u] = 1 + dfs(f[u]);
    };

    int maxDist = 0;
    for (int i = 0; i < n; ++i) {
        maxDist = std::max(maxDist, dfs(i));
    }

    i128 A = 1;
    std::vector<char> seen(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int L = cycleLength[i];
        if (L > 0 && !seen[L]) {
            seen[L] = 1;
            i128 g = igcd(A, (i128)L);
            A = (A / g) * (i128)L;
        }
    }

    if (A == 0) {
        A = 1;
    }
    i128 ans;
    if (maxDist == 0) {
        ans = A;
    } else {
        i128 B = maxDist;
        i128 t = (B + A - 1) / A;
        ans = A * t;
    }
    std::cout << toString(ans) << "\n";
    return 0;
}
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right + 1, true);
        SieveOfEratosthenes(right + 1, prime);
        int ind = left, pnt = -1, ans = std::numeric_limits<int>::max(), left_r = -1, right_r = -1;
        while (ind != right + 1) {
            if (prime[ind] == true && ind >= 2) {
                pnt = ind;
                ind++;
                break;
            }
            ind++;
        }
        while (ind != right + 1) {
            if (prime[ind] == true && ind >= 2) {
                if (ans > ind - pnt) {
                    ans = ind - pnt;
                    left_r = pnt;
                    right_r = ind;
                }
                pnt = ind;
            }
            ind++;
        }

        if (left_r == -1 or right_r == -1) {
            return {-1, -1};
        }

        return {left_r, right_r};
        
    }
private:
    void SieveOfEratosthenes(int n, std::vector <bool> &prime_r) {
        for (int p = 2; p * p <= n; p++) {
            if (prime_r[p] == true) {
                for (int i = p * p; i <= n; i += p) {
                    prime_r[i] = false;
                }
            }
        }
    }
};
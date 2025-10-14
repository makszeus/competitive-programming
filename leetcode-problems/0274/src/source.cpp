class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        std::vector<int> memo(1001, 0);
        
        for (const auto &i: citations)
            if (i >= 1000) ++memo[1000];
            else ++memo[i];
        
        int sum = 0;
        for (int i = 1000; i >= 0; i--){
            sum += memo[i];
            if (sum >= i) return i;
        }
        
        return 0;
    }
};

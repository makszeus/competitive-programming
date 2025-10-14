class Solution {
public:

    std::vector <int> ans;
    void f(const int &low, const int &high, const int &i, const int &num){
        
        if (num >= low && num <= high) ans.push_back(num);
        if (num > high || i > 9) return;

        f (low, high, i + 1, 10 * num + i);
    }
    std::vector<int> sequentialDigits(int low, int high) {
        
        for (size_t i = 1; i <= 9; ++i) f (low, high, i, 0);
        std::sort(ans.begin(),ans.end());
        return ans;
        
    }
    
};

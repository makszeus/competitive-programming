class Solution {
public:
    string reorganizeString(string s) {
        std::string s_new(s.length(), ' ');
        std::unordered_map <char, size_t> x;
        for (const auto &i : s) {
            x[i]++;
        }
        size_t maxValue = 0;
        char maxKey;

        for (const auto &pair : x) {
            if (pair.second > maxValue) {
                maxValue = pair.second;
                maxKey = pair.first;
            }
        }

        if (maxValue > (double)(s.length() + 1) / 2) {
            return "";
        }

        size_t ind = 0;
        while (x[maxKey] > 0) {
            s_new[ind] = maxKey;
            x[maxKey] -= 1;
            ind += 2;
        }
        
        ind = 1;
        size_t total_chars = 0;
        for (const auto& pair : x) {
            total_chars += pair.second;
        }

        while (total_chars > 0) {

            for (auto &pair : x) {
                std::cout << pair.second << " "  << s_new << "\n";
                if (pair.second > 0) {
                    s_new[ind] = pair.first;
                    ind += 1;

                    if (ind < s_new.length() and s_new[ind] != ' ') ind++;
                    pair.second -= 1;
                    total_chars -= 1;
                }
                
            }
        }
        return s_new;
    }
};
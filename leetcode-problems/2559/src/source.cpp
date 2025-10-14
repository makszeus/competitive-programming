class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        std::vector <int> ans;
        std::unordered_set <char> x = {'a', 'o', 'u', 'e', 'i'};
        std::vector <int> p(words.size());
        for (int i = 0; i < words.size(); ++i) {
            if (x.find(words[i][0]) != x.end() and x.find(words[i][words[i].length() - 1]) != x.end()) {
                if (i == 0) p[i]++;
                else p[i] = p[i - 1] + 1;
            }
            else {
                if (i != 0) p[i] = p[i - 1];
            }
        }
        
        for (const auto &i : queries) {
            ans.push_back((i[0] > 0) ? p[i[1]] - p[i[0] - 1] : p[i[1]]);
        }
        return ans;
    }
};
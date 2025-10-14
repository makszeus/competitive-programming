class Solution {
public:
    string sortSentence(string s) {
        unordered_map<int, string> x;
        string currentWord;
        
        for (const auto &c : s) {
            if (isdigit(c)) {
                int position = c - '0';
                x[position] = currentWord;
                currentWord = "";
            } else if (isalpha(c)) {
                currentWord += c;
            }
        }

        string ans;
        for (int i = 1; i <= x.size(); ++i) {
            ans += x[i] + " ";
        }
        ans.pop_back();
        
        return ans;
    }
};

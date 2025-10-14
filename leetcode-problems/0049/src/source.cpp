class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        int n = strs.size();
        std::unordered_map<std::string, std::vector<string>> map;
        std::vector<std::vector<std::string>> ret;
        for (const auto& s : strs) {
            string t = s;
            std::sort(t.begin(), t.end());
            map[t].push_back(s);
        }
        ret.reserve(map.size());
        for (auto& p : map) {
            ret.push_back(std::move(p.second));
        }
        return ret;
    }
};

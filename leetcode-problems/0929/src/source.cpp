class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        unordered_set <string> x;
        size_t ems = emails.size();
        for (size_t i = 0; i < ems; ++i) {

            string tmp; size_t ims = emails[i].length();
            for (size_t j = 0; j < ims; ++j) {

                if (emails[i][j] == '.') continue;
                else if (emails[i][j] == '+') {
                    while (emails[i][j + 1] != '@') ++j;
                    continue;
                }
                else if (emails[i][j] == '@') {
                    tmp += emails[i].substr(j);
                    x.insert(tmp);
                    break;
                }

                tmp += emails[i][j];

            }

        }

        return x.size();

    }
};

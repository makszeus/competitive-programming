class Solution {
public:
    vector<int> minOperations(string boxes) {
        std::vector <int> a(boxes.length());
        int cnt = 0, operations = 0;
        for (int i = 0; i < boxes.length(); ++i) {
            a[i] += operations;
            cnt += (boxes[i] == '1');
            operations += cnt;
        }
        cnt = 0, operations = 0;
        for (int i = boxes.length() - 1; i > -1; --i) {
            a[i] += operations;
            cnt += (boxes[i] == '1');
            operations += cnt;
        }
        return a;
    }
};
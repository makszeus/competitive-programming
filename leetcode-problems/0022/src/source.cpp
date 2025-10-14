void generateParenthesisHelper(std::vector<std::string>& result, std::string current, int open, int close, int n) {
    if (current.size() == 2 * n) {
        result.push_back(current);
        return;
    }

    if (open < n) {
        generateParenthesisHelper(result, current + "(", open + 1, close, n);
    }
    if (close < open) {
        generateParenthesisHelper(result, current + ")", open, close + 1, n);
    }
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    generateParenthesisHelper(result, "", 0, 0, n);
    return result;
}

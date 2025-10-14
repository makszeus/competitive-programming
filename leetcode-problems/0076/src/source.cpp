class Solution {
public:
    std::string minWindow(string source, string target) {
      
      int charCount[128] = {0};
      int targetLength = target.length();
      int startOfSubstring = -1;
      int minSubstringLength = source.length() + 1;
  
      for (const char character : target)
          ++charCount[character];
  
      for (int left = 0, right = 0; right < source.length(); ++right) {
          if (--charCount[source[right]] >= 0)
              --targetLength;
          while (targetLength == 0) {
              if (right - left + 1 < minSubstringLength) {
                  startOfSubstring = left;
                  minSubstringLength = right - left + 1;
              }
              if (++charCount[source[left++]] > 0)
                  ++targetLength;
          }
      }

      return startOfSubstring == -1 ? "" : source.substr(startOfSubstring, minSubstringLength);
    
    }
};

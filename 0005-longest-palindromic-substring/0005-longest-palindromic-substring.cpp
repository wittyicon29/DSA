class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            int left = i, right = i;
            // Expand around the center (single character)
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    maxLen = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
            left = i, right = i + 1;
            // Expand around the center (two characters)
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    maxLen = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, maxLen);
    }
};
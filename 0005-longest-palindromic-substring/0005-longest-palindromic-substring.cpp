class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        int maxlen = 0;
        int start = 0;

        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
            maxlen = 1;
            start = 0;
        }

        for(int len = 2; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if(len == 2) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }

                if(dp[i][j] && len > maxlen) {
                    maxlen = len;
                    start = i;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
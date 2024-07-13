class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        
        vector<string> dp(n + 1);
        dp[1] = "1";
        
        for (int i = 2; i <= n; i++) {
            string current_sequence = "";
            int count = 1;
            for (int j = 0; j < dp[i - 1].length(); j++) {
                if (j == dp[i - 1].length() - 1 || dp[i - 1][j] != dp[i - 1][j + 1]) {
                    current_sequence += to_string(count) + dp[i - 1][j];
                    count = 1;
                } else {
                    count++;
                }
            }
            dp[i] = current_sequence;
        }
        
        return dp[n];
    }
};

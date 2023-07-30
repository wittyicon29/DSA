class Solution {
    public int strangePrinter(String s) {
    int n = s.length();
    int[][] memo = new int[n][n];
    return dp(s, 0, n-1, memo);
}

private int dp(String s, int i, int j, int[][] memo) {
    if (i > j) {
        return 0;
    }
    if (memo[i][j] > 0) {
        return memo[i][j];
    }
    int res = dp(s, i+1, j, memo) + 1;
    for (int k = i+1; k <= j; k++) {
        if (s.charAt(i) == s.charAt(k)) {
            res = Math.min(res, dp(s, i, k-1, memo) + dp(s, k+1, j, memo));
        }
    }
    memo[i][j] = res;
    return res;
}
}
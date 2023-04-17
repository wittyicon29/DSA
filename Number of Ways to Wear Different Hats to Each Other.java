class Solution {
    public int numberWays(List<List<Integer>> hats) {
        int n = hats.size();
        int m = 40;
        int mod = 1000000007;
        List<Integer>[] hatToPerson = new List[m + 1];
        for (int i = 1; i <= m; i++) {
            hatToPerson[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            for (int hat : hats.get(i)) {
                hatToPerson[hat].add(i);
            }
        }
        int[][] dp = new int[1 << n][m + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < (1 << n); j++) {
                dp[j][i] = dp[j][i - 1];
                for (int person : hatToPerson[i]) {
                    if (((j >> person) & 1) == 1) {
                        dp[j][i] = (dp[j][i] + dp[j ^ (1 << person)][i - 1]) % mod;
                    }
                }
            }
        }
        return dp[(1 << n) - 1][m];
    }
}
class Solution {
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;  // There is one way to make 0 amount, with no coins

    // For each coin denomination, update the table for all possible amounts
        for (int coin : coins) {
             for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
            }
        }
        return dp[amount]; 
    }
}
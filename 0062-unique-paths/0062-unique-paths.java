class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n]; // To store the solution of subproblems
        int result = paths(0, 0, m, n, dp);
        return result;
    }
    static int paths(int i, int j, int m, int n, int[][] dp)  {
        if(i == m-1 && j == n-1) // Reached the destination
            return 1;
        
        if(i > m-1 || j > n-1) // When index goes out of the boundary (right boundary aur bottom boundary)
            return 0;
        
        if(dp[i][j] != 0)  // If we already know the solution to this subproblem 
            return dp[i][j];
        
        dp[i][j] = paths(i+1, j, m, n, dp) + paths(i, j+1, m, n, dp);
        return dp[i][j];
    }
}
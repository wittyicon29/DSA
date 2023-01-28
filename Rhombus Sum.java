//https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/
//dp approach 


public class RhombusSums {
    public static List<Integer> topThreeRhombusSums(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] sums = new int[m][n];
        //populating the first row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    sums[i][j] = grid[i][j];
                } else if (i == 0) {
                    sums[i][j] = sums[i][j - 1] + grid[i][j];
                } else if (j == 0) {
                    sums[i][j] = sums[i - 1][j] + grid[i][j];
                }
            }
        }
        //calculating the sums
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                sums[i][j] = grid[i][j] + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
            }
        }
        PriorityQueue<Integer> topThree = new PriorityQueue<>(3, Collections.reverseOrder());
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                int sum = sums[i][j] + sums[i + 1][j + 1] - sums[i][j + 1] - sums[i + 1][j];
                topThree.offer(sum);
                if (topThree.size() > 3) {
                    topThree.poll();
                }
            }
        }

        List<Integer> result = new ArrayList<>(topThree);
        Collections.sort(result, Collections.reverseOrder());
        return result;
    }
}

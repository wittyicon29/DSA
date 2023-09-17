class Solution {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        Queue<int[]> queue = new LinkedList<>();

        boolean[][] visited = new boolean[n][1 << n];

        for(int i = 0; i < n; i++) {
            queue.offer(new int[] {i, 1 << i, 0});
            visited[i][1 << i] = true;
        }

        while(!queue.isEmpty()) {
            int[] curr = queue.poll();
            int node = curr[0], mask = curr[1], dist = curr[2];
            if(mask == (1 << n) - 1) {
                return dist;
            }

            for(int neighbor : graph[node]) {
                int nextMask = mask | (1 << neighbor);
                if(!visited[neighbor][nextMask]) {
                    queue.offer(new int[] {neighbor, nextMask, dist + 1});
                    visited[neighbor][nextMask] = true;
                }
            }
        }
        return -1;
    }
}
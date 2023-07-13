class Solution{
public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList<Integer>[] adj = new ArrayList[numCourses];
        for(int i=0; i<numCourses; i++) {
            adj[i] = new ArrayList<>();
        }
        for(int[] pre : prerequisites) {
            adj[pre[0]].add(pre[1]);
        }
        int[] visited = new int[numCourses];
        for(int i=0; i<numCourses; i++) {
            if( !dfs(i, visited, adj))
                return false;
        }
        return true;
    }
    public boolean dfs(int node, int[] visited, ArrayList<Integer>[] adj) {
        if(visited[node] == 1) {
            return false;
        }
        if(visited[node] == 2) {
            return true;
        }
        visited[node] = 1;
        for(int n : adj[node]) {
            if(!dfs(n, visited, adj))
                return false;
        }   
        visited[node] = 2;
        return true;
    }
} 
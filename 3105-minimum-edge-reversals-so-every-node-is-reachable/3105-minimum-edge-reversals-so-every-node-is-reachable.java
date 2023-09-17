class Solution {
    public int[] minEdgeReversals(int n, int[][] edges) {
      List<int[]>[] nexts = new List[n];
      for(int i=0;i<n;i++) {
        nexts[i] = new ArrayList<>();
      }
      for(int[] edge: edges) {
        int u = edge[0], v = edge[1];
        nexts[u].add(new int[]{1, v});
        nexts[v].add(new int[]{-1, u});
      }
      int[] res = new int[n];
      for(int i=0;i<n;i++) res[i] = -1;
      res[0] = dfs(nexts, 0, -1);
      // System.out.println("res[0]: " + res[0]);
      Queue<Integer> queue = new LinkedList<>();
      queue.add(0);
      while(!queue.isEmpty()) {
        Integer index = queue.remove();
        int val = res[index];
        List<int[]>next = nexts[index];
        for(int[] node: next) {
          if(res[node[1]] == -1) {
            if(node[0] == 1) {
              res[node[1]] = val+1;
            } else {
              res[node[1]] = val-1;
            }
                  // System.out.println("res[ " + node[1] + "]: " + res[node[1]]);

            queue.add(node[1]);
          }
        }
      }
      return res;
    }
    public int dfs(List<int[]>[] nexts, int index, int pre) {
      int res = 0;
      List<int[]> next = nexts[index];
      for(int[] node: next) {
        if(node[1] != pre) {
          if(node[0] == -1){
            //backward
            res++;
          }
          res += dfs(nexts, node[1], index);
        }
      }
      return res;
    }
}
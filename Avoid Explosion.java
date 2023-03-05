/* 
 * The approach used in the solution is Union Find. Union Find is a data structure that is used to keep track of a set of elements partitioned into a number of disjoint subsets. In this problem, we can use Union Find to keep track of the sets of solutions that are safe to mix together.

To do this efficiently, the algorithm needs to know which solutions are already mixed, and which solutions should not be mixed. If two solutions belong to different sets, then they can be safely mixed without causing an explosion. In this case, the algorithm merges the sets of the two solutions by making one of the sets a child of the other.

The time complexity of this algorithm is O(n * m * log n), where n is the number of solutions, and m is the number of combinations that can cause an explosion. This is because we iterate through the array mix of size n and the array danger of size m. For each iteration, we call the find() method, which has a worst-case time complexity of log n. Thus, the overall time complexity is O(n * m * log n).

The space complexity of this algorithm is O(n), which is the size of the ds array.
*/

class Solution{
    ArrayList<String> avoidExplosion(int mix[][], int n , int danger[][], int m){
        int[] ds = new int[n];
        for (int i = 0; i < n; i++) ds[i] = i;
        
        ArrayList<String> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = mix[i][0] - 1, y = mix[i][1] - 1;
            int fx = find(x, ds), fy = find(y, ds);
            boolean is_safe = true;
            for (int j = 0; j < m; j++) {
                int p = danger[j][0] - 1, q = danger[j][1] - 1;
                int fp = find(p, ds), fq = find(q, ds);
                if ((fx == fp && fy == fq) || (fx == fq && fy == fp)) {
                    is_safe = false;
                    break;
                }
            }
            res.add(is_safe ? "Yes" : "No");
            if (is_safe) ds[fx] = fy;
        }
        
        return res;
    }
    
    private int find(int x, int[] ds) {
        if (ds[x] != x) 
            ds[x] = find(ds[x], ds);
        return ds[x];
    
    }
}
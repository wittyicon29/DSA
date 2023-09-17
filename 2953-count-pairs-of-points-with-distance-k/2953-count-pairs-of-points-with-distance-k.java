class Solution {
    public int countPairs(List<List<Integer>> coordinates, int k) {
        Map<Long, Integer> map = new HashMap<>();
        int ans = 0;
        for (List<Integer> coord : coordinates) {
            int x = coord.get(0), y = coord.get(1);
            for (int ix = 0; ix <= k; ix++)
                ans += map.getOrDefault(((long)(ix ^ x) << 32) | ((k - ix) ^ y), 0);
            long s = ((long)x << 32) | y;
            map.put(s, 1 + map.getOrDefault(s, 0));
        }
        return ans;
    }
}
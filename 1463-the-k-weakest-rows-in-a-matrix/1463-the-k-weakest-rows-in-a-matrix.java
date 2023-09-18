class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        List<Integer> list = new ArrayList<>();

        for(int i = 0; i < mat.length; i++) {
            int count = 0;
            for(int j = 0; j < mat[i].length; j++) {
                if(mat[i][j] == 1) {
                    count++;
                } else {
                    break;
                }
            }
            list.add(count * 100 + i);
        }
        Collections.sort(list);
        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = list.get(i) % 100; // decode the row index from the encoded integer
        }
        return result;
    }
}
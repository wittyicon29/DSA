class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (a, b) -> a[1] - b[1]);
    
    int count = 1; // Count of pairs in longest chain
    int[] prevPair = pairs[0]; // Previous pair in chain
    
    for (int i = 1; i < pairs.length; i++) {
        int[] currPair = pairs[i];
        
        // Check if current pair can be added to chain
        if (currPair[0] > prevPair[1]) {
            count++;
            prevPair = currPair;
        }
    }
    
    return count;
    }
}
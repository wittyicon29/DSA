class Solution {
    public int[] findRightInterval(int[][] intervals) {
    // Create an array to store the result
    int[] result = new int[intervals.length];
    
    // Create a TreeMap to store the intervals based on their start values
    TreeMap<Integer, Integer> intervalMap = new TreeMap<>();
    
    // Populate the TreeMap with intervals and their corresponding indices
    for (int i = 0; i < intervals.length; i++) {
        intervalMap.put(intervals[i][0], i);
    }
    
    // Iterate through each interval
    for (int i = 0; i < intervals.length; i++) {
        // Get the current interval's end value
        int endValue = intervals[i][1];
        
        // Find the interval with the smallest start value greater than or equal to the end value
        Integer rightIntervalIndex = intervalMap.ceilingKey(endValue);
        
        // If a right interval exists, store its index in the result array
        if (rightIntervalIndex != null) {
            result[i] = intervalMap.get(rightIntervalIndex);
        } else {
            // If no right interval exists, store -1 in the result array
            result[i] = -1;
        }
    }
    
    return result;
}

}
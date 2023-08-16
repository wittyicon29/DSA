class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
    if (nums == null || nums.length == 0 || k <= 0) {
        return new int[0];
    }
    
    int n = nums.length;
    int[] result = new int[n - k + 1];
    Deque<Integer> deque = new LinkedList<>();
    
    for (int i = 0; i < n; i++) {
        // remove elements that are outside the current sliding window
        while (!deque.isEmpty() && deque.peek() < i - k + 1) {
            deque.poll();
        }
        
        // remove elements that are smaller than the current element
        while (!deque.isEmpty() && nums[deque.peekLast()] < nums[i]) {
            deque.pollLast();
        }
        
        // add the current element to the deque
        deque.offer(i);
        
        // add the maximum element in the sliding window to the result
        if (i - k + 1 >= 0) {
            result[i - k + 1] = nums[deque.peek()];
        }
    }
    
    return result;
}

}
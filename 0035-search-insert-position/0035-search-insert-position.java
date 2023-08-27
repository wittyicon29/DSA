class Solution {
    public int searchInsert(int[] nums, int target) {
       int start = 0;
    int end = nums.length;

    while(start<end){
    if(nums[start] == target){
        return start;
    }
    
    if(nums[start]>target){
        return start;
    }

    start++;
    }
 return nums.length;
    }
}
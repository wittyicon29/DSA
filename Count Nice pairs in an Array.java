//https://leetcode.com/problems/count-nice-pairs-in-an-array/description
//Using HashMap
class Solution {
    public int countNicePairs(int[] nums) {
        long modulo = (long)Math.pow(10, 9) + 7L;
        long result = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for(int curr : nums){
            int diff = curr - rev(curr);
            map.put(diff, map.getOrDefault(diff, 0)+1);
        }
        for(Integer key : map.keySet()){
            int count = map.get(key);
            result += (count*(count-1L))/2L;
        }
        return (int) (result % modulo);
    }
    public int rev(int value){
        int result = 0;
        while(value != 0){
            result = (result * 10) + (value % 10);
            value /= 10;
        }
        return result;
    } 
}
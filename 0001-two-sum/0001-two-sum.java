class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        HashMap<Integer,Integer> mp = new HashMap<>();
        int[] res = new int[2];
        for(int i=0;i<n;i++){
            if(mp.containsKey(target-nums[i])){
                res[1] = i;
                res[0] = mp.get(target-nums[i]);
                return res;
            }
            mp.put(nums[i],i);
        }
        return res;
    }
}
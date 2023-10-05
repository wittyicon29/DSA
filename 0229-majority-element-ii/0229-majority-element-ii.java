class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> result = new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<>();

    // count the frequency of each element
    for (int num : nums) {
        map.put(num, map.getOrDefault(num, 0) + 1);
    }

    // find elements that appear more than floor(n/3) times
    int threshold = nums.length / 3;
    for (int key : map.keySet()) {
        if (map.get(key) > threshold) {
            result.add(key);
        }
    }

    return result;
    }
}
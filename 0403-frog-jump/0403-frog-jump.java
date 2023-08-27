class Solution {
    public boolean canCross(int[] stones) {
        Set<Integer> stoneSet = new HashSet<>();
        Map<Integer, Set<Integer>> steps = new HashMap<>();

        for(int stone : stones) {
            stoneSet.add(stone);
            steps.put(stone, new HashSet<>());
        }

        steps.get(0).add(0);

        for(int stone : stones) {
            for(int prevStep : steps.get(stone)) {
                for(int nextStep = prevStep - 1; nextStep <= prevStep + 1; nextStep++) {
                    if(nextStep > 0 && stone + nextStep <= stones[stones.length - 1] && stoneSet.contains(stone + nextStep)) {
                        steps.get(stone + nextStep).add(nextStep);
                    }
                }
            }
         }
         return !steps.get(stones[stones.length - 1]).isEmpty();
    }
}
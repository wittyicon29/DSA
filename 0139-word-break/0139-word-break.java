class Solution {

    boolean flag = false;

    HashMap<String, Boolean> dp = new HashMap<>();

    public boolean solve(String s, List<String> wordDict) {
        if(s.length() == 0) return true;
        if(dp.containsKey(s)) return dp.get(s);

        for(String word : wordDict) {
            if(s.startsWith(word)) {
                flag = flag || solve(s.substring(word.length()), wordDict);
            }
        }
        dp.put(s, flag);
        return dp.get(s);
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        return solve(s, wordDict);
    }
}
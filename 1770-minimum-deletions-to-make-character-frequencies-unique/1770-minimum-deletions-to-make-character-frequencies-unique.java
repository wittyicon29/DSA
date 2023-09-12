class Solution {
    public static int minDeletions(String s) {
    int[] freq = new int[26];
    for (char c : s.toCharArray()) {
        freq[c - 'a']++;
    }
    Set<Integer> freqValues = new HashSet<>();
    int deletions = 0;
    for (int v : freq) {
        while (freqValues.contains(v) && v > 0) {
            v--;
            deletions++;
        }
        freqValues.add(v);
    }
    return deletions;
}

}
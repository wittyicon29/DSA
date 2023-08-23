class Solution {
    public String reorganizeString(String s) {
        int[] freq = new int[26];
        for(char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        PriorityQueue<Character> pq = new PriorityQueue<>((a, b) -> freq[b - 'a'] - freq[a - 'a']);
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                pq.offer((char) ('a' + i));
            }
        }

        StringBuilder sb = new StringBuilder();
        while(!pq.isEmpty()) {
            char curr = pq.poll();
            if(sb.length() == 0 || curr != sb.charAt(sb.length() - 1)) {
                sb.append(curr);
                freq[curr - 'a']--;
                if(freq[curr - 'a'] > 0) {
                    pq.offer(curr);
                }
            } else {
                if(pq.isEmpty()) {
                    return "";
                }
                char next = pq.poll();
                sb.append(next);
                freq[next - 'a']--;
                if(freq[next - 'a'] > 0) {
                    pq.offer(next);
                }
                pq.offer(curr);
            }
        }
        return sb.toString();
    }
}
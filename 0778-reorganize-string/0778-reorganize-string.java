class Solution {
    public String reorganizeString(String s) {
        int[] freq = new int[26];
        // Calculating the frequency of each charcater
        for(char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        // // Create a priority queue that orders characters by decreasing frequency
        PriorityQueue<Character> pq = new PriorityQueue<>((a, b) -> freq[b - 'a'] - freq[a - 'a']);
        // Adding each character in the priority queue in decreasing order of frequency
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                pq.offer((char) ('a' + i));
            }
        }

        StringBuilder sb = new StringBuilder();

        // Iterate over the charcters in the queue
        while(!pq.isEmpty()) {
            // Selecting the character with the highest frequency
            char curr = pq.poll();
            // Add the character to the result string if it does not violate the adjacent character constraint
            if(sb.length() == 0 || curr != sb.charAt(sb.length() - 1)) {
                sb.append(curr);
                freq[curr - 'a']--;
                 // Add the character back to the priority queue if it still has non-zero frequency
                if(freq[curr - 'a'] > 0) {
                    pq.offer(curr);
                }
            } else {
                // If the next character in the priority queue is the same as the last character added to the result string,
            // we need to select the next highest frequency character that is different from the last character
                if(pq.isEmpty()) {
                    return "";
                }
                char next = pq.poll();
                sb.append(next);
                freq[next - 'a']--;
                // Add the character back to the priority queue if it still has non-zero frequency
                if(freq[next - 'a'] > 0) {
                    pq.offer(next);
                }
                pq.offer(curr);
            }
        }
        return sb.toString();
    }
}
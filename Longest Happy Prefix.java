//https://leetcode.com/problems/longest-happy-prefix/description/
//KMP Algorithm - The Knuth-Morris-Pratt (KMP) algorithm is a string matching algorithm that is used to find the occurrence of a pattern within a larger string. It is more efficient than the brute force string matching algorithm, which checks every character in the text for a match with the pattern. The KMP algorithm uses information about the pattern itself to avoid checking characters in the text that are guaranteed not to match the pattern.
//The basic idea behind the KMP algorithm is to preprocess the pattern to create a "partial match" table, which helps the algorithm to determine where to continue searching in the text when a mismatch occurs. The algorithm uses this table to skip ahead in the text, rather than checking every single character. This can greatly reduce the running time of the algorithm, especially for long patterns and texts.
//The KMP algorithm has a time complexity of O(n + m), where n is the length of the text and m is the length of the pattern. This is significantly faster than the brute force algorithm, which has a time complexity of O(nm).
public class Solution{
    public String longestPrefix(String s) {
        int[] pre = new int[s.length()];
        Arrays.fill(pre, -1);
        int i = 1 , j = 0;
        int max = -1;
        while(i < s.length()){
            if(s.charAt(i) == s.charAt(j)){
                pre[i] = j;
                i++;
                j++;
            } else if(j > 0){
                j = pre[j-1]+1;
            } else {
                i++;
            }
        }
        max = pre[s.length()-1];
        return s.substring(0, max+1);
    }
}
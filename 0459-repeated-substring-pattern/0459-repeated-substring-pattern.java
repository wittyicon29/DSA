class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int n = s.length();
        int[] lps = new int[n];
        int i = 1;
        int len = 0;
        
        while (i < n) {
            if (s.charAt(i) == s.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len-1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        int lpsLength = lps[n-1];
        
        return lpsLength > 0 && n % (n - lpsLength) == 0;
    }
}
//https://leetcode.com/problems/fraction-to-recurring-decimal/description/
//using hashmap

class Solution {
    public String fractionToDecimal(int n, int d) {
        long a = Math.abs((long)n);
        long b = Math.abs((long)d);
        StringBuilder s = new StringBuilder();
        if((n < 0 && d > 0) || (n > 0 && d < 0))
           s.append('-');
        s.append(a/b);
        a = (a % b);
        if(a > 0)
          s.append('.');
        HashMap<Long, Integer>  map = new HashMap<>();
        while(!map.containsKey(a)){
            map.put(a, map.size());
            a = a*10;
            if(a > 0){
                s.append(a/b);
            }
            a = a%b;
        }
        if(a > 0){
            s.insert(s.length()-(map.size()-map.get(a)) , '(');
            s.append(')');
        }
        return s.toString();
    }
}

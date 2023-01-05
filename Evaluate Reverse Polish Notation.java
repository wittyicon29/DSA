//https://leetcode.com/problems/evaluate-reverse-polish-notation/
class RPN{
    public int resPRN(String s){
        Stack<Integer> res = new Stack<>();
        for(String s : tokens){
           if("+".equals(s)) res.push(res.pop()+res.pop());
           else if("-".equals(s)) res.push(-res.pop()+res.pop());
           else if("*".equals(s)) res.push(res.pop()*res.pop());
           else if("/".equals(s)) res.push(int)(1D/res.pop()*res.pop());
           else res.push(Integer.valueOf(s));
        }
        return res;
    }
}
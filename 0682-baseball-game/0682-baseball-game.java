class Solution {
    public int calPoints(String[] ops) {
        Map<String, Integer> map = new HashMap<>();
        Stack<Integer> stack = new Stack<>();
        int sum = 0;
        for (String op : ops) {
            if (op.equals("+")) {
                int top = stack.pop();
                int newTop = top + stack.peek();
                stack.push(top);
                stack.push(newTop);
                sum += newTop;
            } else if (op.equals("D")) {
                int doubleScore = 2 * stack.peek();
                stack.push(doubleScore);
                sum += doubleScore;
            } else if (op.equals("C")) {
                int lastScore = stack.pop();
                sum -= lastScore;
            } else {
                int score = Integer.parseInt(op);
                stack.push(score);
                sum += score;
            }
        }
        return sum;
    }
}
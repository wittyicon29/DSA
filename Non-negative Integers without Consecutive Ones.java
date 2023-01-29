//https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/
//Recursive solution

class Solution {
    int count = 2;
    public int findIntegers(int n) {
        dfs(1, 1, n);
        return count;
    }
    public void dfs(int prev, int num, int n){
        if(num*2 <= n){
            count++;
            dfs(0, num*2, n);
        }
        if(prev == 0 && num*2+1 <= n){
            count++;
            dfs(1, num*2+1, n);
        }
    }
}

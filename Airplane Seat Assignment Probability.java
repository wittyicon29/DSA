//https://leetcode.com/problems/airplane-seat-assignment-probability/description/
//Explainations: https://leetcode.com/problems/airplane-seat-assignment-probability/solutions/411905/it-s-not-obvious-to-me-at-all-foolproof-explanation-here-and-proof-for-why-it-s-1-2/
image.png
public class Solution{
    public double nthPersonGetsNthSeat(int n) {
        if(n==1)
            return 1;
        else
            return 0.5;
    }
}

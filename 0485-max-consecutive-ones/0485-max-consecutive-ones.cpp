class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecutive = 0;
        int currConsecutive = 0;

        for(auto num : nums) {
            if(num == 1) {
                currConsecutive += 1;
            } else {
                currConsecutive = 0;
            }
            if(currConsecutive > maxConsecutive) {
                maxConsecutive = currConsecutive;
            }
        }
        return maxConsecutive;
    }
};
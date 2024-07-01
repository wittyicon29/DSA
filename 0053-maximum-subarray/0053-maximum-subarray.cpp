class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubarrayHelper(nums, 0, nums.size() - 1);
    }

private:
    int maxSubarrayHelper(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        int mid = (left + right) / 2;
        int leftMax = maxSubarrayHelper(nums, left, mid);
        int rightMax = maxSubarrayHelper(nums, mid + 1, right);
        int crossMax = findCrossMaxSubarray(nums, left, mid, right);

        return max(leftMax, max(rightMax, crossMax));
    }

    int findCrossMaxSubarray(vector<int>& nums, int left, int mid, int right) {
        int leftSum = INT_MIN, rightSum = INT_MIN, currentSum = 0;

        // Find the maximum subarray from the left half
        for (int i = mid; i >= left; i--) {
            currentSum += nums[i];
            leftSum = max(leftSum, currentSum);
        }

        currentSum = 0;
        // Find the maximum subarray from the right half
        for (int i = mid + 1; i <= right; i++) {
            currentSum += nums[i];
            rightSum = max(rightSum, currentSum);
        }

        return leftSum + rightSum;
    }
};

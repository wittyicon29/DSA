class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> result;
    std::deque<int> deque;
    int n = nums.size();

    // Process the first window
    for (int i = 0; i < k; i++) {
        while (!deque.empty() && nums[deque.back()] < nums[i]) {
            deque.pop_back();
        }
        deque.push_back(i);
    }

    // Process the remaining windows
    for (int i = k; i < n; i++) {
        result.push_back(nums[deque.front()]);

        // Remove elements from the deque that are out of the current window
        if (deque.front() == i - k) {
            deque.pop_front();
        }

        // Remove elements from the deque that are smaller than the current element
        while (!deque.empty() && nums[deque.back()] < nums[i]) {
            deque.pop_back();
        }

        deque.push_back(i);
    }

    // Add the last window's maximum
    result.push_back(nums[deque.front()]);

    return result;
    }
};
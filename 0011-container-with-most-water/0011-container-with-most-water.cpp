class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int maxWater = 0;

        int left = 0, right = height.size() - 1;

        while(left < right) {
            int minHeight = min(height[left], height[right]);
            int width = right - left;
            int area = minHeight * width;
            maxWater = max(maxWater, area);

            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};
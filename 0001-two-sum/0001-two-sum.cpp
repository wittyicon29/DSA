class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complement_map;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (complement_map.find(complement) != complement_map.end()) {
                result.push_back(complement_map[complement]);
                result.push_back(i);
                return result;
            }
            complement_map[nums[i]] = i;
        }

        return result;
    }
};

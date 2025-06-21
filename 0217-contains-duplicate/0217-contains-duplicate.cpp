class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums) {
            if(freq.find(num) != freq.end()) {
                return true;
            }
            freq[num] = 1;
        }
        return false;
    }
};
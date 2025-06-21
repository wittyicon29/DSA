class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int longest = 1;
        unordered_set<int> s;
        for(int num : nums) {
            s.insert(num);
        }
        for(auto num : s) {
            if(s.find(num - 1) == s.end()) {
                int cnt = 1;
                int x = num;
                while(s.find(x + 1) != s.end()) {
                    cnt++;
                    x++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};
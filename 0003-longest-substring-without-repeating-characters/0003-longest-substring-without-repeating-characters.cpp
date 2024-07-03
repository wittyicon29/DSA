class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left = 0;
        int right =  0;
        int maxlen = 0;

        while(right < s.length()) {
            if(set.find(s[right]) == set.end()) {
                set.insert(s[right]);
                right++;
                maxlen = max(maxlen, static_cast<int>(set.size()));
            } else {
                set.erase(s[left]);
                left++;
            }
        }
        return maxlen;
    }
};
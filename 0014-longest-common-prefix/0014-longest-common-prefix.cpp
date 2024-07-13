class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int minlen = INT_MAX;

        for(auto& str : strs) {
            minlen = min(minlen, (int)str.length());
        }
        string prefix = "";

        for (int i = 0; i < minlen; i++) {
            char c = strs[0][i];
            for (const auto& str : strs) {
                if (str[i] != c) {
                    return prefix;
                }
            }
            prefix += c;
        }
        return prefix;
    }
};
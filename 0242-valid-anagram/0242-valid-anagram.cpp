class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<int,int> s_mp;
        unordered_map<int,int> t_mp;

        for(int i=0; i<s.size(); i++){
            s_mp[s[i]]++;
            t_mp[t[i]]++;
        }

        return s_mp == t_mp;
    }
};
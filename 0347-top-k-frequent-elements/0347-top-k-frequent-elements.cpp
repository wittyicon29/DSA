class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            map[nums[i]]++;
        }
        vector<pair<int, int>> p(map.begin(), map.end());
        sort(p.begin(), p.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        });

        for(int i = 0; i < k; i++) {
            ans.push_back(p[i].first);
        }
        return ans;
    }
};
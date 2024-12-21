class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int, vector<int>> tree;

        for(const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        int validComponents = 0;

        function<long long(int, int)> dfs = [&] (int node, int parent) {
            long long totalSum = values[node];

            for(int neighbor : tree[node]) {
                if(neighbor == parent) continue;
                long long subtreeSum = dfs(neighbor, node);
                totalSum += subtreeSum;

                if(subtreeSum % k == 0) {
                    validComponents++;
                }
            }
            return totalSum;
        };

        long long totalSum = dfs(0, -1);
        return validComponents + (totalSum % k == 0);
    }
};
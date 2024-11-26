class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> in_degree(n, 0);
        vector<int> out_degree(n, 0);

        for(const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            out_degree[u]++;
            in_degree[v]++;
        }

        vector<int> champions;

        for(int i = 0; i < n; i++) {
            if(in_degree[i] == 0) {
                champions.push_back(i);
            }
        }

        if(champions.size() == 1) {
            return champions[0];
        } else {
            return -1;
        }
    }
};
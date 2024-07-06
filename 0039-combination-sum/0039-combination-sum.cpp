class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        backtrack(candidates, target, 0, currentCombination, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& currentCombination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }

        if (target < 0 || start >= candidates.size()) {
            return;
        }

        // Include the current candidate
        currentCombination.push_back(candidates[start]);
        backtrack(candidates, target - candidates[start], start, currentCombination, result);
        currentCombination.pop_back();

        // Exclude the current candidate
        while (start + 1 < candidates.size() && candidates[start] == candidates[start + 1]) {
            start++;
        }
        backtrack(candidates, target, start + 1, currentCombination, result);
    }
};

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_score = 0;
        int max_i_value = values[0] + 0;
        int n = values.size();

        for (int j = 1; j < values.size(); ++j) {
            // Calculate the score using the maximum value found so far
            int score = max_i_value + values[j] - j;
            max_score = max(max_score, score);

            // Update the maximum value for the next iteration
            max_i_value = max(max_i_value, values[j] + j);
        }
        return max_score;
    }
};
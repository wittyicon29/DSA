class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> answer = prices;
        stack<int> stack;

        for(int i = 0; i < n; i++) {
            while(!stack.empty() && prices[i] <= prices[stack.top()]) {
                int j = stack.top();
                stack.pop();
                answer[j] -= prices[i];
            }
            stack.push(i);
        }
        return answer;
    }
};
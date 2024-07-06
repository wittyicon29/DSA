class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<int> board(n, -1);
    backtrack(solutions, board, 0, n);
    return solutions;
    }

    void backtrack(vector<vector<string>>& solutions, vector<int>& board, int row, int n) {
        if (row == n) {
            solutions.push_back(construct_solution(board, n));
            return;
        }

        for (int col = 0; col < n; col++) {
            if (is_safe(board, row, col)) {
                board[row] = col;
                backtrack(solutions, board, row + 1, n);
                board[row] = -1;
            }
        }
    }

    bool is_safe(vector<int>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i] == col || abs(i - row) == abs(board[i] - col)) {
                return false;
            }
        }
        return true;
    }

    vector<string> construct_solution(vector<int>& board, int n) {
        vector<string> solution(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            solution[i][board[i]] = 'Q';
        }
        return solution;
    }
};
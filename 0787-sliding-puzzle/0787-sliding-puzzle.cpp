class Solution {
public:
    bool isSolvable(const vector<vector<int>>& board) {
        vector<int> flatboard;

        for(const auto& row : board) {
            for(int num : row) {
                if(num != 0) {
                    flatboard.push_back(num);
                }
            }
        }
        int inversions = 0;

        for(int i = 0; i < flatboard.size(); i++) {
            for(int j = i + 1; j < flatboard.size(); j++) {
                if(flatboard[i] > flatboard[j]) {
                    ++inversions;
                }
            }
        }
        return inversions % 2 == 0;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string start;

        for(const auto& row : board) {
            for(int num : row) {
                start += to_string(num);
            }
        }    
        if(!isSolvable(board)) {
            return -1;
        }

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({start, start.find('0')});
        visited.insert(start);

        int moves = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                auto [current, zeroIndex] = q.front();
                q.pop();

                if(current == target) {
                    return moves;
                }
                int zeroRow = zeroIndex / 3;
                int zeroCol = zeroIndex % 3;

                for(const auto& dir : directions) {
                    int newRow = zeroRow + dir.first;
                    int newCol = zeroCol + dir.second;

                    if(newRow >= 0 && newRow < 2 && newCol >= 0 && newCol < 3) {
                        int newZeroIndex = newRow * 3 + newCol;
                        string newBoard = current;

                        swap(newBoard[zeroIndex], newBoard[newZeroIndex]);

                        if(visited.find(newBoard) == visited.end()) {
                            visited.insert(newBoard);
                            q.push({newBoard, newZeroIndex});
                        }
                    }
                }
            }
            ++moves;
        } 
        return -1;
    }
};
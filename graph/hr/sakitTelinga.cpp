#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

struct PuzzleState {
    vector<vector<int>> board;
    int zeroRow;
    int zeroCol;
    string moves;

    PuzzleState(const vector<vector<int>>& _board, int _zeroRow, int _zeroCol, const string& _moves)
        : board(_board), zeroRow(_zeroRow), zeroCol(_zeroCol), moves(_moves) {}
};

bool isGoalState(const vector<vector<int>>& board) {
    int num = 1;
    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == rows - 1 && j == cols - 1) {
                if (board[i][j] != 0) {
                    return false;
                }
            } else {
                if (board[i][j] != num) {
                    return false;
                }
                num++;
            }
        }
    }

    return true;
}

void swapPositions(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

vector<PuzzleState> getNextStates(const PuzzleState& state) {
    vector<PuzzleState> nextStates;
    const vector<vector<int>>& board = state.board;
    int zeroRow = state.zeroRow;
    int zeroCol = state.zeroCol;

    // Move the tile above the empty space
    if (zeroRow > 0) {
        vector<vector<int>> newBoard = board;
        swapPositions(newBoard[zeroRow][zeroCol], newBoard[zeroRow - 1][zeroCol]);
        nextStates.emplace_back(newBoard, zeroRow - 1, zeroCol, state.moves + "U");
    }

    // Move the tile below the empty space
    if (zeroRow < 2) {
        vector<vector<int>> newBoard = board;
        swapPositions(newBoard[zeroRow][zeroCol], newBoard[zeroRow + 1][zeroCol]);
        nextStates.emplace_back(newBoard, zeroRow + 1, zeroCol, state.moves + "D");
    }

    // Move the tile to the left of the empty space
    if (zeroCol > 0) {
        vector<vector<int>> newBoard = board;
        swapPositions(newBoard[zeroRow][zeroCol], newBoard[zeroRow][zeroCol - 1]);
        nextStates.emplace_back(newBoard, zeroRow, zeroCol - 1, state.moves + "L");
    }

    // Move the tile to the right of the empty space
    if (zeroCol < 2) {
        vector<vector<int>> newBoard = board;
        swapPositions(newBoard[zeroRow][zeroCol], newBoard[zeroRow][zeroCol + 1]);
        nextStates.emplace_back(newBoard, zeroRow, zeroCol + 1, state.moves + "R");
    }

    return nextStates;
}

string solvePuzzle(const vector<vector<int>>& initialBoard) {
    queue<PuzzleState> q;
    unordered_set<string> visited;

    int zeroRow, zeroCol;
    int rows = initialBoard.size();
    int cols = initialBoard[0].size();

    // Find the position of the empty space (zero)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (initialBoard[i][j] == 0) {
                zeroRow = i;
                zeroCol = j;
                break;
            }
        }
    }

    PuzzleState initialState(initialBoard, zeroRow, zeroCol, "");
    q.push(initialState);
    visited.insert(initialState.moves);

    while (!q.empty()) {
        PuzzleState currState = q.front();
        q.pop();

        if (isGoalState(currState.board)) {
            return currState.moves;
        }

        vector<PuzzleState> nextStates = getNextStates(currState);
        for (const auto& nextState : nextStates) {
            if (visited.find(nextState.moves) == visited.end()) {
                q.push(nextState);
                visited.insert(nextState.moves);
            }
        }
    }

    return "Kerjain dl aja kerjaannya";
}

int main() {
    vector<vector<int>> initialBoard(3, vector<int>(3));

    cout << "Enter the initial state of the puzzle (3x3 matrix with numbers 0-8):" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> initialBoard[i][j];
        }
    }

    string solution = solvePuzzle(initialBoard);

    if (solution == "Kerjain dl aja kerjaannya") {
        cout << solution << endl;
    } else {
        cout << "Langkah minimum = " << solution.length() << endl;
        cout << solution << endl;
    }

    return 0;
}

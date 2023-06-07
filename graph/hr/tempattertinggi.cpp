#include <iostream>
#include <vector>
#include <string>

using namespace std;

void simulateVistetris(vector<string>& board) {
    int rows = board.size();
    int cols = board[0].size();

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == '*') {
                int k = i;
                while (k + 1 < rows && board[k + 1][j] == '.') {
                    swap(board[k][j], board[k + 1][j]);
                    k++;
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int rows, cols;
        cin >> rows >> cols;

        vector<string> board(rows);
        for (int i = 0; i < rows; i++) {
            cin >> board[i];
        }

        simulateVistetris(board);

        for (int i = 0; i < rows; i++) {
            cout << board[i] << endl;
        }
    }

    return 0;
}

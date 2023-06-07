#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& matrix, int row, int col) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    if (row < 0 || row >= numRows || col < 0 || col >= numCols || matrix[row][col] != 1) {
        return;
    }

    matrix[row][col] = -1; 

    dfs(matrix, row - 1, col); 
    dfs(matrix, row + 1, col); 
    dfs(matrix, row, col - 1); 
    dfs(matrix, row, col + 1); 
}

int countIslands(vector<vector<int>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    int islandCount = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (matrix[i][j] == 1) {
                islandCount++;
                dfs(matrix, i, j);
            }
        }
    }

    return islandCount;
}

int main() {
    vector<vector<int>> inputMatrix(10, vector<int>(10));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> inputMatrix[i][j];
        }
    }

    int islandCount = countIslands(inputMatrix);
    cout << islandCount << endl;

    return 0;
}
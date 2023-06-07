#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isValidMove(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int findShortestPath(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;

    // Temukan koordinat Start
    int startX, startY;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                startX = i;
                startY = j;
                break;
            }
        }
    }

    // Tambahkan Start ke antrian dan tandai sebagai sudah dikunjungi
    q.push({startX, startY});
    visited[startX][startY] = true;

    // Gerakan yang mungkin: atas, kanan, bawah, kiri
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // Jika ditemukan harta rampasan perang, kembalikan langkah yang diperlukan
        if (grid[x][y] == 3) {
            return visited[x][y] - 1;
        }

        // Coba semua gerakan yang mungkin
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // Periksa apakah gerakan valid dan belum dikunjungi sebelumnya
            if (isValidMove(newX, newY, n) && !visited[newX][newY] && grid[newX][newY] != 1) {
                q.push({newX, newY});
                visited[newX][newY] = visited[x][y] + 1;
            }
        }
    }

    // Jika tidak ada jalan yang dapat mencapai harta rampasan perang, kembalikan -1
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    // Membaca matriks dari input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int shortestPath = findShortestPath(grid);

    if (shortestPath == -1) {
        cout << "yah" << endl;
    } else {
        cout << "yey" << endl;
    }

    return 0;
}

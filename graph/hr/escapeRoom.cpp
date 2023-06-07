#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& rooms, int visited[], int key) {
    visited[key] = 1;
    for (int i=0; i<rooms[key].size(); i++) {
        if (visited[rooms[key][i]] == 0) {
            dfs(rooms, visited, rooms[key][i]);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int visited[1005] = {0};
    dfs(rooms, visited, 0);
    for (int i=0; i<rooms.size(); i++) {
        if (visited[i] == 0) {
            cout << i << endl;
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> room(n);
    for (int i=0; i<n; i++) {
        int number, many;
        cin >> number >> many;
        for (int j=0; j<many; j++) {
            int keys;
            cin >> keys;
            room[i].push_back(keys);
        }
    }
    if (canVisitAllRooms(room)) {
        cout << "berhasil" << endl;
    }
    else {
        cout << "gagal" << endl;
    }
}
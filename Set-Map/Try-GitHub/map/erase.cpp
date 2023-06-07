#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int, int> m;

    m.insert({1, 2});
    m.insert(make_pair(2, 3));
    m.insert(pair<int, int>(3, 4));
    m[4] = 5;
    m[5]++;
    m[6] = 6;

    m.erase(1);
    // menghapus elemen map dengan key = 1

    auto pointer1 = m.find(2);
    m.erase(pointer1);
    // menggunakan iterator dari fungsi find

    auto pointer2 = m.find(5);
    m.erase(m.begin(), pointer2);
    // menghapus semua elemen dengan key < 5

    m[5] = 0;
    /*
    tidak benar-benar menghapus, hanya merubah
    value menjadi 0 pada elemen dengan key = 5
    */

    for(auto i = m.begin(); i != m.end(); i++){
        cout << i->first << " " << i->second << endl;
    }

    return 0;
}
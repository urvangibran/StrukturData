#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;

    s.insert(4);
    s.insert(3);
    s.insert(2);
    s.insert(1);

    auto pointer = s.find(1);

    s.erase(pointer);
    // menggunakan iterator

    for(auto i = s.begin(); i != s.end(); i++){
        cout << *i << endl;
    }

    return 0;
}
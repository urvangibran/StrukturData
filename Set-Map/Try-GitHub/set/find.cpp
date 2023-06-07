#include <bits/stdc++.h>
using namespace std;

int main(){
    set<string> s;

    s.insert("4");
    s.insert("3");
    s.insert("2");
    s.insert("1");

    auto pointer = s.find("6");

    if(pointer == s.end()){
        cout << "data tidak ditemukan" << endl;
    }
    else{
        cout << "data ditemukan" << endl;
    }

    return 0;
}
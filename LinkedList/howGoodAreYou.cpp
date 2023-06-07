#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;
    for(int i=0; i<n.length(); i++)
    {
        if(n[i] - '0' < 5) n[i] = '0';
        else if(n[i] - '0' >= 5 ) n[i] = '1';
    }
    cout << n;
}
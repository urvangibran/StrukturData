#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mySet[] = {3, 5, 2, 3, 5, 1};
    set<int> s (mySet, mySet + 6);

    if(s.count(111) == 1)
        cout << "ADAA" << endl;
    else cout << "GAADA" << endl;

    // for(auto i = s.begin(); i != s.end(); i++)
    //     cout << *i << endl;
    return 0;
}
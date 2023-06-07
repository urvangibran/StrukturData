#include <bits/stdc++.h>
using namespace std;

int main(){
    int arrSet[] = {51, 23, 41, 4, 12};
    set<int, greater<int>> s (arrSet, arrSet + 5);
    
    set<int>::reverse_iterator rit;
    for(rit = s.rbegin(); rit != s.rend(); rit++)
        cout << *rit << endl;

    // for(auto i = s.begin(); i != s.end(); i++)
    //     cout << *i << endl;

}
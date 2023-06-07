#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    set<string> myset;

    myset.emplace("foo");
    myset.emplace("bar");
    myset.emplace("aa");
    myset.emplace("baa");

    auto ret = myset.emplace("br");

    if (!ret.second)
        cout << ret.second <<" already exists in myset\n";
    else
        cout << ret.second <<" not already exists in myset\n";
        

    for (auto i = myset.begin(); i != myset.end(); i++)
    {
        cout << *i << endl;
    }
    

    return 0;
}
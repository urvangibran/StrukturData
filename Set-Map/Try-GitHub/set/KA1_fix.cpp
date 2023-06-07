#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    set<string> s;
    map<string, int> count;
    string word;
    int kamus_1 = 0, kamus_2 = 0;
    for (int i = 0; i < tc; i++)
    {
        cin >> word;
        auto pointer = s.find(word);
        if (pointer == s.end())
        {
            s.insert(word); 
            kamus_1++; 
            cout << word << " masuk Kamus 1!" << endl;
        }
        else
        {
            if (count[word] > 0)
            {
                cout << "aku tidak bisa masuk Kamus!" << endl;
            }
            else
            {
                count[word]++;
                kamus_2++;
                cout << word << " masuk Kamus 2!" << endl;
            }
        }
    }
    cout << "Kamus 1 berisi " << kamus_1 << " kata" << endl;
    cout << "Kamus 2 berisi " << kamus_2 << " kata" << endl;

    return 0;
}

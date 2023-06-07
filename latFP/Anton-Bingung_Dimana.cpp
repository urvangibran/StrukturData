#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<string> dq;
    dq.push_back("home");
    dq.push_back("anton");
    int n;
    cin >> n;
    while (n--)
    {
        string opr;
        cin >> opr;
        if (opr == "goto")
        {
            string path;
            cin >> path;
            dq.push_back(path);
        }
        else if (opr == "whereami")
        {
            if (dq.empty())
                cout << "i am nowhere";
            else
            {
                deque<string> cek, temp = dq;
                while (!temp.empty())
                {
                    cek = temp;
                    cek.pop_front();
                    cout << temp.front();
                    if (!cek.empty())
                        cout << "/";
                    temp.pop_front();
                }
            }
            cout << "\n";
        }
        else if (opr == "goback")
        {
            if (dq.empty())
                cout << "cannot go back\n";
            else
            {
                dq.pop_back();
            }
        } else {
            cout << "Query not found" << endl;
        }
    }
    return 0;
}
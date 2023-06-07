#include <iostream>
#include <stack>
#include <deque>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    stack<int> st1, st2;
    deque<int> ans;
    int size = max(m, n);
    int num;
    while (m--)
    {
        cin >> num;
        st1.push(num);
    }
    while (n--)
    {
        cin >> num;
        st2.push(num);
    }

    int carry = 0;
    while (!st1.empty() || !st2.empty() || carry)
    {
        int sum = carry;
        if (!st1.empty())
        {
            sum += st1.top();
            st1.pop();
        }
        if (!st2.empty())
        {
            sum += st2.top();
            st2.pop();
        }
        carry = sum / 10;
        sum %= 10;
        ans.push_front(sum);
    }

    while (!ans.empty())
    {
        cout << ans.front();
        ans.pop_front();
    }
    return 0;
}

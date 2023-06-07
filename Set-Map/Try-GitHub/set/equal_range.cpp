// set::equal_elements
#include <iostream>
#include <set>
using namespace std;

int main ()
{
  set<int> myset;

  for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

  pair<set<int>::const_iterator,set<int>::const_iterator> ret;
  ret = myset.equal_range(10);

  cout << "the lower bound points to: " << *ret.first << '\n';
  cout << "the upper bound points to: " << *ret.second << '\n';

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define READ_SPEED cin.tie(0)->sync_with_stdio(0);
#define MOD 1000000007
#define MAXN 100000
#define INF 0x3f3f3f3f

class comp
{
public:
  // Se a função retornar true, Y é mais prioritário que X
  bool operator()(const pair<int, int> x, const pair<int, int> y) const
  {
    if (x.second == y.second)
    {
      return x.first > y.first;
    }
    return x.second > y.second;
  }
};

int main()
{
  READ_SPEED;

  priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

  return 0;
}
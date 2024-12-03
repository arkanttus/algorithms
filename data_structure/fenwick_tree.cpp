#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define READ_SPEED cin.tie(0)->sync_with_stdio(0);
#define MOD 1000000007
#define MAXN 100000
#define INF 0x3f3f3f3f

void update(int bit[], int n, int idx, int val)
{
  while (idx <= n)
  {
    bit[idx] += val;
    // retorna o valor do bit menos significativo
    idx += (idx & -idx);
  }
}

int soma(int bit[], int idx)
{
  int sum = 0;
  while (idx > 0)
  {
    sum += bit[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

int soma_range(int bit[], int l, int r) {
    return soma(r) - soma(l - 1);
}

int main()
{
  READ_SPEED;

  int n, num;

  cin >> n;

  int conts[n + 2] = {0}, bit[n + 2] = {0};

  for (int i = 0; i < n; ++i)
  {
    cin >> num;

    cout << num - soma(bit, num);

    if (i < n - 1)
      cout << " ";

    conts[num] = 1;

    update(bit, n, num, 1);
  }

  cout << endl;

  return 0;
}
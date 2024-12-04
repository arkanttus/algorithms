#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define READ_SPEED cin.tie(0)->sync_with_stdio(0);
#define MOD 1000000007
#define MAXN 100000
#define INF 0x3f3f3f3f

void update(int bit[], int n, int idx, int val)
{
  // index in BITree[] is 1 more than the index in arr[]
  idx = idx + 1;

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

int soma_range(int bit[], int l, int r)
{
  return soma(bit, r + 1) - soma(bit, l);
}

int main()
{
  //   READ_SPEED;

  int n, num, l, r;

  cin >> n;

  int bit[n + 2] = {0};

  for (int i = 0; i < n; ++i)
  {
    cin >> num;

    update(bit, n, i, num);
  }

  cout << "Print bit: " << endl;

  for (int i = 0; i < n + 2; ++i)
  {
    cout << bit[i] << " ";
  }

  cout << endl;

  cout << soma(bit, 3) << endl;

  cout << "Entre com index left e right:" << endl;

  cin >> l >> r;

  // Soma do index l até r
  cout << soma_range(bit, l, r) << endl;

  return 0;
}
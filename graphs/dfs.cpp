#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define READ_SPEED cin.tie(0)->sync_with_stdio(0);
#define MOD 1000000007
#define MAXN 100000
#define INF 0x3f3f3f3f

void dfs(vector<vector<int>> adj, int start_node, int visited[])
{
  visited[start_node] = true;
  cout << start_node << " ";

  for (int next_node : adj[start_node])
    if (!visited[next_node])
      dfs(adj, next_node, visited);
}
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

int main()
{
  int vertices = 5;

  vector<vector<int>> adj(vertices);

  // add vertices
  // adj[a] -> [..., b, c]
  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[1].push_back(3);
  adj[1].push_back(4);
  adj[2].push_back(4);

  int visited[vertices + 1] = {0};

  dfs(adj, 0, visited);
}
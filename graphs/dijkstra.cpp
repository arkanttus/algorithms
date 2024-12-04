#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define READ_SPEED cin.tie(0)->sync_with_stdio(0);
#define MOD 1000000007
#define MAXN 100000
#define INF 0x3f3f3f3f

typedef pair<int, int> ii;

void dijkstra(vector<vector<ii>> adj, int sn, int dist[], int visited[])
{
  dist[sn] = 0;
  priority_queue<ii, vector<ii>, greater<ii>> pq;

  // {dist, node}
  pq.push({0, sn});

  while (!pq.empty())
  {
    int curr_node = pq.top().second;
    pq.pop();

    if (visited[curr_node])
      continue;

    visited[curr_node] = true;

    for (auto edge : adj[curr_node])
    {
      int next_node = edge.first, weight = edge.second;

      if (dist[next_node] > dist[curr_node] + weight)
      {
        dist[next_node] = dist[curr_node] + weight;
        pq.push({dist[next_node], next_node});
      }
    }
  }
}

int main()
{
  int vertices = 6;

  vector<vector<ii>> adj(vertices);

  int dist[vertices];

  fill(dist, dist + vertices, INF);

  int visited[vertices + 1] = {0};

  adj[0].push_back({1, 2});
  adj[0].push_back({2, 4});
  adj[1].push_back({0, 2});
  adj[1].push_back({3, 5});
  adj[2].push_back({0, 4});
  adj[2].push_back({3, 1});
  adj[2].push_back({4, 5});
  adj[3].push_back({1, 5});
  adj[3].push_back({2, 1});
  adj[3].push_back({4, 2});
  adj[4].push_back({2, 5});
  adj[4].push_back({3, 2});

  dijkstra(adj, 0, dist, visited);

  cout << dist[0] << endl;
  cout << dist[1] << endl;
  cout << dist[2] << endl;
  cout << dist[3] << endl;
  cout << dist[4] << endl;
}
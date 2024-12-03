#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define READ_SPEED cin.tie(0)->sync_with_stdio(0);
#define MOD 1000000007
#define MAXN 100000
#define INF 0x3f3f3f3f

void bfs(vector<vector<int>> &adj, int start_node, int visited[])
{
  // Gerenciar os nós a serem visitados
  queue<int> fila;

  // Adiciona o nó inicial
  visited[start_node] = true;
  fila.push(start_node);

  while (!fila.empty())
  {
    int current_node = fila.front();
    fila.pop();

    cout << current_node << " ";

    for (int next_node : adj[current_node])
    {
      if (!visited[next_node])
      {
        visited[next_node] = true;
        fila.push(next_node);
      }
    }
  }

  cout << endl;
}

void bfs_with_path(vector<vector<int>> &adj, int start_node, int destiny, vector<int> &par, vector<int> &dist)
{
  // Gerenciar os nós a serem visitados
  queue<int> fila;

  // Adiciona o nó inicial
  dist[start_node] = 0;
  fila.push(start_node);

  bool achou = false;

  while (!fila.empty() and !achou)
  {
    int current_node = fila.front();
    fila.pop();

    for (int next_node : adj[current_node])
    {
      if (dist[next_node] == 1e9)
      {
        par[next_node] = current_node;
        dist[next_node] = dist[current_node] + 1;
        fila.push(next_node);
      }

      if (next_node == destiny)
      {
        cout << dist[next_node] << endl;
        achou = true;
        return;
      }
    }
  }
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

  bfs(adj, 0, visited);
}
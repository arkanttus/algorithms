#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define READ_SPEED cin.tie(0)->sync_with_stdio(0);
#define MOD 1000000007
#define MAXN 100000
#define INF 0x3f3f3f3f
#define V 4 // ATUALIZAR PARA A QUANTIDADE DE ARESTAS QUE A QUESTAO PEDIR

void printSolution(int dist[][V]);

void floydWarshall(int dist[][V])
{
  int i, j, k;

  for (k = 0; k < V; k++)
  {
    for (i = 0; i < V; i++)
    {
      for (j = 0; j < V; j++)
      {
        if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }

  printSolution(dist);
}

void printSolution(int dist[][V])
{
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      if (dist[i][j] == INF)
        cout << "INF"
             << " ";
      else
        cout << dist[i][j] << "   ";
    }
    cout << endl;
  }
}

int main()
{
  int graph[V][V] = {{0, 5, INF, 10},
                     {INF, 0, 3, INF},
                     {INF, INF, 0, 1},
                     {INF, INF, INF, 0}};

  floydWarshall(graph);
  return 0;
}

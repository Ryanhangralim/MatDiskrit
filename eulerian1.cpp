#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

// Global variable
int n;

void isEulerian(vector<int> adj[])
{
  int oddDegreeV = 0;

  for (int i = 0; i < n; i++)
  {
    if (adj[i].size() & 1)
    {
      oddDegreeV++;
    }
  }
  cout << "Odd Degree Vertex: " << oddDegreeV << "\n";

  if (oddDegreeV == 0)
  {
    cout << "Graph is eulerian circuit";
  }
  else if (oddDegreeV == 2)
  {
    cout << "Graph is eulerian path";
  }
  else
  {
    cout << "Graph is not eulerian";
  }
  cout << "\n";
}

void dfs(int source, int col, int *matrix, vector<bool> &vis)
{
  if (vis[source])
    return;
  vis[source] = true;
  for (int i = 0; i < col; i++)
  {
    if (*((matrix + source * col) + i) && !vis[i])
    {
      cout << source << "->" << i << "\n";
      dfs(i, col, matrix, vis);
    }
  }
}

bool isConnected(vector<bool> vis)
{
  for (bool ele : vis)
  {
    if (!ele)
      return false;
  }
  return true;
}

void rmvEdge(int u, int v, vector<int> *adj)
{
  // Find v in u array then change the value to -1 to 'remove' edge, and do otherwise
  auto it_u = find((adj + u)->begin(), (adj + u)->end(), v);
  auto it_v = find((adj + v)->begin(), (adj + v)->end(), u);
  *it_u = -1;
  *it_v = -1;
}

void addEdge(int u, int v, vector<int> *adj)
{
  (adj + u)->push_back(v);
  (adj + v)->push_back(u);
}

int dfsCount(int source, vector<int> *adj, vector<bool> &vis)
{
  // Mark current source as visited
  vis[source] = true;
  int count = 1;

  for (int v : *(adj + source))
  {
    if (v != -1 && !vis[v])
    {
      // cout << source << "->" << v << "\n";
      count += dfsCount(v, adj, vis);
    }
  }
  return count;
}

bool isValidNextEdge(int u, int v, vector<int> *adj)
{
  // Conditions if next edge is valid:
  // 1. That edge is the only available edge
  cout << "u: " << u << ", v: " << v << "\n";
  int count = 0;
  for (int v : *(adj + u))
  {
    if (v != -1)
    {
      count++;
    }
  }
  cout << "count: " << count << "\n";
  if (count == 1)
  {
    return true;
  }
  // 2. That edge is not bridge. It means when bridge is remove, the reachable vertex
  // from u does does not decrease
  vector<bool> vis1(n, false);
  vector<bool> vis2(n, false);
  int count1 = dfsCount(u, adj, vis1);
  rmvEdge(u, v, adj);
  int count2 = dfsCount(u, adj, vis2);
  addEdge(u, v, adj);

  cout << "count1: " << count1 << "\n";
  cout << "count2: " << count2 << "\n";

  return (count1 > count2) ? false : true;
}

void printEulerPath(int u, vector<int> *adj)
{
  vector<int> newAdj;
  cout << "adjacent: ";
  for (int v : *(adj + u))
  {
    cout << v << " ";
    newAdj.push_back(v);
  }
  cout << "\n";

  cout << "New adjacent: ";
  for (int v : newAdj)
  {
    cout << v << " ";
  }
  cout << "\n";
  // Iterate through all vertex adjacent to u
  for (auto it = newAdj.begin(); it != newAdj.end(); it++)
  {
    cout << "this is the v: " << *it << "\n";
    // If v is not -1 (u-v removed) and u-v is a valid next
    if (*it != -1 && isValidNextEdge(u, *it, adj))
    {
      cout << u << " -> " << *it << "\n";
      // Remove edge
      rmvEdge(u, *it, adj);
      // Call printEulerPath starting from v now
      printEulerPath(*it, adj);
      continue;
    }
  }
}

void printEuler(vector<int> *adj)
{
  // Start from odd degree vertex if exist
  int u = 0;
  for (int i = 0; i < n; i++)
  {
    if ((adj + i)->size() & 1)
    {
      u = i;
      break;
    }
  }
  // Print path starting from u
  printEulerPath(u, adj);
}

int main()
{
  system("cls");
  string namaFile;

  // Ask for matrix file
  cout << "Masukkan nama file matrix: ";
  cin >> namaFile;
  cout << "Jumlah vertex: ";
  cin >> n;

  fstream f(namaFile);
  if (!f.is_open())
  {
    cout << "Can't open file...";
    return -1;
  }

  // Store matrix in 2d array
  int matrix[n][n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      f >> matrix[i][j];
    }
  }
  f.close();

  // Show graph in matrix
  cout << "Menampilkan grap dalam matriks ketetanggaan\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";

  // Insert into adjacent
  vector<int> adj[n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (matrix[i][j])
      {
        adj[i].push_back(j);
      }
    }
  }

  // Print adj
  // for (int i = 0; i < v; i++)
  // {
  //   for (auto ele : adj[i])
  //   {
  //     cout << ele << " ";
  //   }
  //   cout << "\n";
  // }

  vector<bool> vis(n, false);
  dfs(1, n, &matrix[0][0], vis);
  if (isConnected(vis))
  {
    cout << "Connected Graph\n";
    isEulerian(adj);
    printEuler(&adj[0]);
  }
  else
  {
    cout << "Unconnected Graph\n";
  }
}
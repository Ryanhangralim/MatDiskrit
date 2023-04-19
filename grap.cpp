#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
  int num;
  int degree;
  vector<int> adj;
} vertex;

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

int dfsColor(vertex vertices[], vector<int> adj[], vector<bool> &colored, int v)
{
  int counter = 0;
  for (int i = 0; i < v; i++)
  {
    // If vertex is colored, skip this vertex
    if (colored[i])
      continue;
    // Start coloring
    counter++;         // Increment counter
    colored[i] = true; // Set this vertex's colored to true
    vector<int> sameColorVertex = {vertices[i].num};
    for (int j = i + 1; j < v; j++)
    {
      if (colored[j])
        continue;
      vector<int> currAdj = adj[j];
      // If sameColorVertex's elements is in currAdj, don't color this vertex because they adjacent
      bool isAdj = false;
      for (int ele : sameColorVertex)
      {
        if (find(currAdj.begin(), currAdj.end(), ele) != currAdj.end())
        {
          isAdj = true;
        }
      }
      if (isAdj)
        continue;
      colored[j] = true;
      sameColorVertex.push_back(vertices[j].num);
    }
    for (bool ele : colored)
    {
      cout << ele << " ";
    }
    cout << "\n";
  }
  return counter;
}

int main()
{
  string namaFile;
  int v;

  cout << "Masukkan nama file matrix: ";
  cin >> namaFile;
  cout << "Jumlah vertex: ";
  cin >> v;

  fstream f(namaFile);
  if (!f.is_open())
  {
    cout << "Can't open file...";
    return -1;
  }

  int matrix[v][v];
  for (int i = 0; i < v; i++)
  {
    for (int j = 0; j < v; j++)
    {
      f >> matrix[i][j];
    }
  }
  f.close();

  // Check if grap is connected
  vector<bool> vis(v, false);
  // Call dfs()
  dfs(0, v, &matrix[0][0], vis);
  // Call isConnected()
  if (isConnected(vis))
  {
    cout << "Grap terhubung\n";
  }
  else
  {
    cout << "Grap tidak terhubung\n";
  };

  // Grap Coloring
  vertex vertices[v];

  // Insert degree and adjacents
  for (int i = 0; i < v; i++)
  {
    vertices[i].degree = 0;
    vertices[i].num = i;
    for (int j = 0; j < v; j++)
    {
      if (matrix[i][j])
      {
        vertices[i].degree++;
        vertices[i].adj.push_back(j);
      }
    }
  }

  // Test print vertices
  for (vertex ele : vertices)
  {
    cout << "num: " << ele.num << '\n';
    cout << "degree: " << ele.degree << "\n";
    cout << "adj: ";
    for (int ele : ele.adj)
    {
      cout << ele << ", ";
    }
    cout << "\n\n";
  }

  // Selection short -> later change to bubble short
  int tmp;
  vertex tmp_v;
  for (int i = 0; i < v; i++)
  {
    int max = i;
    tmp = vertices[i].degree;
    for (int j = i + 1; j < v; j++)
    {
      if (vertices[j].degree > tmp)
      {
        tmp = vertices[j].degree;
        max = j;
      }
    }
    tmp_v = vertices[i];
    vertices[i] = vertices[max];
    vertices[max] = tmp_v;
  }

  // Test print vertices after sorting
  for (vertex ele : vertices)
  {
    cout << "num: " << ele.num << '\n';
    cout << "degree: " << ele.degree << "\n";
    cout << "adj: ";
    for (int ele : ele.adj)
    {
      cout << ele << ", ";
    }
    cout << "\n\n";
  }

  // Push each vertex's adjacent to an array
  vector<int> adj[v];
  for (int i = 0; i < v; i++)
  {
    adj[i] = (vertices[i].adj);
  }

  vector<bool> colored(v, false);
  int result = dfsColor(vertices, adj, colored, v);

  cout << "Warna minimum: " << result << "\n";
}
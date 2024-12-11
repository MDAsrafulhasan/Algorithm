vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {

  vector<int> dis(n + 1, 1e8);

  dis[src] = 0;
  for (int k = 1; k <= n - 1; k++) 
  {
    for (int i = 0; i < m; i++) 
    {
      int u = edges[i][0];
      int v = edges[i][1];
      int w = edges[i][2];

      if (dis[v] > dis[u] + w) 
      {
        dis[v] = dis[u] + w;
      }
    }
  }

  return dis;
}
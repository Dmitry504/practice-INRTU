#include <iostream>
#include <vector>

void dfs(int v, const std::vector<std::vector<int>>& g, std::vector<bool>& visited) {
  visited[v] = true;
  for (int u : g[v]) {
    if (!visited[u]) {
      dfs(u, g, visited);
    }
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  std::vector<bool> visited(n, false);
  int components = 0;

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i, g, visited);
      components++;
    }
  }

  std::cout << (components - 1) << std::endl;

  return 0;
}

#include <iostream>
#include <vector>



int main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<long long> streets(n + 1, 0); // улицы от 1 до n

  for (int i = 0; i < k; ++i) {
    int type;
    std::cin >> type;
    if (type == 1) {
      int ix;
      long long x;
      std::cin >> ix >> x;
      streets[ix] += x;
    }
    else if (type == 2) {
      int u, r;
      std::cin >> u >> r;
      long long sum = 0;
      for (int j = u; j <= r; ++j) {
        sum += streets[j];
      }
      std::cout << sum << std::endl;
    }
  }

  return 0;
}
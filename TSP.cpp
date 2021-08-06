#include <algorithm>
#include <iostream>
#include <vector>

// For 6 cities:
//
// 0 9 14 2 6 11
// 9 0 4 1 7 6
// 14 4 0 2 10 9
// 2 1 2 0 5 12
// 6 7 10 5 0 3
// 11 6 9 12 3 0
//
// Ans: 23

std::vector<int> create_perm(int N) {
  std::vector<int> perm;
  for (int i = 1; i < N; i++) {
    perm.push_back(i);
  }
  return perm;
}

int len_of_path(const std::vector<int> &perm,
                const std::vector<std::vector<int>> &connections) {
  int size = perm.size();
  int prev = 0;
  int len = 0;
  for (int i = 0; i < size; i++) {
    int cur = perm[i];
    len += connections[cur][prev];
    prev = cur;
  }
  len += connections[0][prev];
  return len;
}

int main(void) {

  int N;
  std::cin >> N;

  if (N > 6 || N < 4) {
    std::cout << "There must be at least 4,5 or 6 cities";
    return 0;
  }

  std::vector<std::vector<int>> connections(N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int tmp = -1;
      std::cin >> tmp;
      if (tmp < 0) {
        std::cout << "Road's lenght must be positive";
        return 0;
      }
      connections[i].push_back(tmp);
    }
  }

  std::vector<int> perm = create_perm(N);
  int minlen = len_of_path(perm, connections);
  while (std::next_permutation(perm.begin(), perm.end())) {
    minlen = std::min(len_of_path(perm, connections), minlen);
  }
  std::cout << minlen;

  return 0;
}

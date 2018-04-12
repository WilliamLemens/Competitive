#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>

void addEdge(std::vector<int> g[], int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}

void wipe(bool flag[], int N) {
  for (int i = 0; i < N; i++)
    flag[i] = false;
}

void zero(int arr[], int len) {
  for (int i = 0; i < len; i++)
    arr[i] = 0;
}

void flagComponent(int v, std::vector<int> g[], bool flag[]) {
  flag[v] = true;

  for (int i = 0; i < g[v].size(); i++)
    if (!flag[ g[v][i] ])
      flagComponent(g[v][i], g, flag);
}

int getNumComponents(std::vector<int> g[], int N) {
  int count = 0;
  bool flag[N];
  wipe(flag, N);

  // let's find the number of components
  int i = 0;
  while (++i < N) // iterate over all nodes, skipping ones that've been touched.
    if (!flag[i]) { // new component! Flag all connected (DFS), and increment.
      flagComponent(i, g, flag);
      count++;
    }
  return count;
}

int getNumReachable(std::vector<int> g[], int N, int S, int P) {
  bool flag[N];
  wipe(flag, N);

  std::deque<int> q;
  // Want to keep track of how deep we are without making a new struct
  int currentDepth = 0, count = 1, numAtDepth[P+1];
  zero(numAtDepth, P+1);
  // Start at S
  q.push_front(S);
  flag[S] = true;
  numAtDepth[0] = 1;

  while (q.size() > 0 && currentDepth != P) { // BFS
    int k = q.front();
    q.pop_front();

    for (int i = 0; i < g[k].size(); i++) // iterate over every adjacent node
      if (!flag[ g[k][i] ]) { // is adj node flagged?
        flag[ g[k][i] ] = true; // is now, anyway
        numAtDepth[currentDepth+1]++; // add adj to count for next depth
        q.push_back(g[k][i]); // we'll want to iterate over it
      }

    if (--numAtDepth[currentDepth] == 0) // last at current depth?
      count += numAtDepth[++currentDepth]; // add num at next depth to total count
  }

  return count;
}

int main() {
  int numtests;
  std::cin >> numtests;
  for (int test = 0; test < numtests; test++) {
    int N, M, S, P, b = 1;
    std::cin >> N; // nodes
    std::cin >> M; // edges
    std::cin >> S; // start
    std::cin >> P; // max depth

    N++; // Because we're starting counting nodes at 1 for some reason, index 0 unused.

    std::vector<int> g[N];
    for (int edge = 0; edge < M; edge++) {
      int u, v;
      std::cin >> u;
      std::cin >> v;
      addEdge(g, u, v);
    }

    // All set, let's find stuff out.
    std::cout << getNumComponents(g, N) << " " << getNumReachable(g, N, S, P) << std::endl;
  }
}

#include <stdio.h>
#include <iostream>
#include <list>
#include <iterator>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

struct Cmp {
  bool operator ()(const pair<int, int> &a, const pair<unsigned int, double> &b)
    { return a.second > b.second; }
};

void addEdge(vector< pair<int,int> > g[], int u, int v, int w) {
  g[u].push_back(make_pair(v,w));
  g[v].push_back(make_pair(u,w));
}

int main() {
  int n, m;
  cin >> n >> m;

  priority_queue< pair<int,int>,vector<pair<int,int>>,Cmp> S; // Priority queue that puts lowest weight first
  vector< pair<int,int> > graph[n];
  int dist[n];
  bool visited[n];

  for (int i = 0; i < n; i++) // zero out graph
    dist[i] = -1, visited[i] = false;

  for (int i = 0; i < m; i++) { // read in graph
    int u, v, s, l;
    cin >> u >> v >> s >> l;
    a--, b--; // because counting starts at 0.
    int w = l/s;
    addEdge(graph, a, b, w);
  }

  // ok, got our graph. Now do Dijkstra's.
  dist[0] = 0;
  pair<int,int> next = make_pair(0,0); // begin at the beginning

  while (next.first != n-1) {

    int u = next.first;
    visited[u] = true; // y'know... because we're here right now.

    for (auto it = graph[u].begin(); it != graph[u].end(); ++it) {
      pair<int,int> p = *it; // yeah, it's a pair
      int v = p.first; // our second vertex

      if (!visited[v]) { // Child node hasn't been visited
        int dij = p.second + dist[u];
        if (dist[v] == -1 || dij < dist[v]) // if this is the quickest path known to it
          dist[v] = dij; // update distance
        pair<int,int> s = make_pair(v, dist[v]);
        S.push(s);
      }
    }
    if (S.size() == 0) // out of paths, if we ain't there, no path.
      break;
    next = S.top();
    S.pop();
  }

  if (next.first == n-1) {
    printPath(parent, n);
    return 0;
  }
  cout << -1 << endl;
}

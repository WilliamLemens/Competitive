#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 101;

bool bfs(int graph[MAX_N][MAX_N], int N, int s, int t, int parent[]) {
    // Create a visited array and mark all vertices as not visited
    bool visited[N];
    memset(visited, 0, sizeof(visited));
 
    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v = 0; v < N; v++)
        {
            if (!visited[v] && graph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t] == true);
}
 
// Returns the maximum flow from s to t in the given graph
int ford_fulkerson(int graph[MAX_N][MAX_N], int s, int t) {
    int u, v;
 
    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    int rGraph[V][V]; // Residual graph where rGraph[i][j] indicates 
                     // residual capacity of edge from i to j (if there
                     // is an edge. If rGraph[i][j] is 0, then there is not)  
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];
 
    int parent[V];  // This array is filled by BFS and to store path
 
    int max_flow = 0;  // There is no flow initially
 
    // Augment the flow while tere is path from source to sink
    while (bfs(rGraph, s, t, parent))
    {
        // Find minimum residual capacity of the edges along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
 
        // update residual capacities of the edges and reverse edges
        // along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        // Add path flow to overall flow
        max_flow += path_flow;
    }
 
    // Return the overall flow
    return max_flow;
}

int main() {
    int T, N, M, S, P, H, u, v, c;

    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        // READ IN
        scanf("%d %d %d %d", &N, &M, &S, &P);
        int G[N][N];
        for (int m = 0; m < M; m++) {
            scanf("%d %d %d", &u, &v, &c);
            G[u][v] = c;
        }
        for (int j = 0; j < S; j++) {
            scanf("%d", &H);
            G[H][0] = INT_MAX;
        }
        /*
        // CHECK READ
        printf("%d %d %d %d %d\n", N, M, S, P, H);
        for (int n = 0; n < N+1; n++) {
            printf("%d:\n", n);
            for (int i = 0; i < G.V[n].E.size(); i++)
                printf("    %d %d %d\n", G.V[n].E[i].u, G.V[n].E[i].v, G.V[n].E[i].c);
        }
        */
        // FEED TO EDMONDS-KARP'S
        int maxSaved = edmonds_karp(G, N, S, 0);
        // OUTPUT
        if (maxSaved >= P)
            printf("YES\n");
        else
            printf("NO %d\n", maxSaved);
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct Edge { int u, v, c, f; };

struct Vertex {
    std::vector<Edge> E;
};

struct Graph {
    int n, m;
    std::vector<Vertex> V;
    Graph(int N, int M) {
        n = N;
        m = M;
        V.resize(n);
    }
    void addVertex(int u) {
        n++;
        V.push_back(Vertex());
    }
    void addEdge(int u, int v, int c, int f) {
        m++;
        bool contains = false;
        for (int i = 0; i < V[u].E.size(); i++)
            if (V[u].E[i].v == v) {
                contains = true;
                break;
            }
        if (!contains)
            V[u].E.push_back({u, v, c, f});
    }
    void addEdge(Edge e) { addEdge(e.u, e.v, e.c, e.f); }
};

bool BFS(Graph G, int s, int t, Edge parent[]) {
    bool visited[G.n];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < G.V[u].E.size(); i++) {
            int v = G.V[u].E[i].v;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                parent[v] = G.V[u].E[i];
            }
        }
    }
    return visited[t];
}

int edmonds_karp(Graph G, int s, int t) {
    int u, v;
    Graph R = Graph(G.n, G.m * 2); // Residual graph
    for (int i = 0; i < G.n; i++) // Generate residual and zero flows
        for (int j = 0; j < G.V[i].E.size(); j++) {
            G.V[i].E[j].f = 0;
            R.addEdge(G.V[i].E[j]);
            R.addEdge(G.V[i].E[j].v, G.V[i].E[j].u, G.V[i].E[j].c, 0);
        }
    Edge parent[R.n];
    int max_flow = 0;
    while (BFS(R, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v].u;
            path_flow = min(path_flow, parent[v].f);
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v].u;
            parent[v].f -= path_flow;
            for (int i = 0; i < R.V[v].E.size(); i++) {
                if (R.V[v].E[i].v == u) {
                    
                }
            }
        }
        math_flow += path_flow;
/*
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
*/
    }
    return max_flow;
}

int main() {
    int T, N, M, S, P, H, u, v, c;

    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        // READ IN
        scanf("%d %d %d %d", &N, &M, &S, &P);
        Graph G = Graph(N+1, M+S);
        for (int m = 0; m < M; m++) {
            scanf("%d %d %d", &u, &v, &c);
            G.addEdge({u, v, c, 0});
        }
        for (int j = 0; j < S; j++) {
            scanf("%d", &H);
            G.addEdge({H, 0, INT_MAX, 0});
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
        int maxSaved = edmonds_karp(G, S, 0);
        // OUTPUT
        if (maxSaved >= P)
            printf("YES\n");
        else
            printf("NO %d\n", maxSaved);
    }

    return 0;
}

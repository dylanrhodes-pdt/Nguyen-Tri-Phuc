/// ---------- /// dylanrhodes /// ---------- ///
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 300005;
int n,m,s,t;
struct edge {
    int v,f,c,rev;
};
vector <edge> adj[N];
int level[N],start[N];

void make_edge (int u,int v,int c) {
    adj[u].push_back({v,0,c,adj[v].size()});
    adj[v].push_back({u,0,0,adj[u].size()-1});
}

bool bfs () {
    for (int i = s; i <= t; i++)
        level[i] = 0;
    level[s] = 1;
    deque <int> dq;
    dq.push_back(s);

    while (dq.size()) {
        int cur = dq.front();
        dq.pop_front();

        for (int i = 0; i < adj[cur].size(); i++) {
            edge e = adj[cur][i];

            if (level[e.v] == 0 && e.f < e.c) {
                level[e.v] = level[cur] + 1;
                dq.push_back(e.v);
            }
        }
    }

    return level[t] != 0;
}

int dfs (int u,int flow) {
    if (u == t)
        return flow;

    for (; start[u] < adj[u].size(); start[u]++) {
        int i = start[u];
        edge e = adj[u][i];

        if (level[e.v] == level[u] + 1 && e.f < e.c) {
            int newflow = min(flow,e.c - e.f);
            int Inc = dfs(e.v,newflow);

            if (Inc > 0) {
                adj[u][i].f += Inc;
                adj[e.v][e.rev].f -= Inc;
                return Inc;
            }
        }
    }

    return 0;
}

int Dinic () {
    int maxflow = 0;

    while (bfs()) {
        for (int i = s; i <= t; i++)
            start[i] = 0;

        int flow = dfs(s,INT_MAX);
        while (flow > 0) {
            maxflow += flow;
            flow = dfs(s,INT_MAX);
        }
    }

    return maxflow;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        make_edge(u,v,w);
    }

    cout << Dinic();
    return 0;
}

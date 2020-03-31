#include <bits/stdc++.h>

using namespace std;

const int mod = 1007050321;
const int base = 521;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const int inf = 2e9;

int n,m;
int active[N],pa[N];
vector <int> adj[N];
stack <int> st;
bool visit[N],mark[N];
vector <int> Component[N];

int Find (int u) {
    if (pa[u] == u)
        return u;
    return pa[u] = Find(pa[u]);
}

void dfs (int u) {
    visit[u] = 1;
    st.push(u);
    pa[u] = u;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (visit[v]) {
            v = Find(active[v]);
            while (st.top() != v) {
                pa[Find(st.top())] = v;
                st.pop();
            }
        }
    }
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!visit[v]) {
            active[u] = v;
            dfs(v);
        }
    }
    if (st.top() == u)
        st.pop();
}

int main() {
    ios_base :: sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
        if (!visit[i])
            dfs(i);

    for (int i = 1; i <= n; ++i) {
        mark[Find(i)] = 1;
        Component[Find(i)].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        if (mark[i]) {
            for (int j = 0; j < Component[i].size(); ++j)
                cout << Component[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}

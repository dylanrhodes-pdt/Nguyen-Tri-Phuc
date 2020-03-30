#include <bits/stdc++.h>
#define task "capital"

using namespace std;

const int mod = 1007050321;
const int base = 521;
const int N = 3e5 + 5;
const int MOD = 1e9 + 7;
const int inf = 2e9;

int n,m;
vector <int> adj[N];
int khop[N];
int num[N],low[N];

void dfs (int u,int pa) {
    int con = 0;
    num[u] = low[u] = ++num[0];
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v != pa) {
            if (num[v])
                low[u] = min(low[u],num[v]);
            else {
                dfs(v,u);
                low[u] = min(low[u],low[v]);
                con++;
                if (u == pa && con >= 2)
                    khop[u] ++;
                else if (u != pa && low[v] >= num[u])
                    khop[u] ++;
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(0),cin.tie(0),cout.tie(0);

    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int tplt = 0;
    for (int i = 1; i <= n; ++i)
        if (!num[i])
            dfs(i,i),tplt++;

    int mcum = -1;
    for (int i = 1; i <= n; ++i) {
        if (mcum == -1 || khop[i] == 1 && khop[i] > khop[mcum])
            mcum = i;
    }

    cout << mcum << " " << tplt + khop[mcum];
    return 0;
}

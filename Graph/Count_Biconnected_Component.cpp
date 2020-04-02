#include <bits/stdc++.h>

using namespace std;

const int mod = 1007050321;
const int base = 521;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const int inf = 2e9;

int n,m,num[N],low[N],ans = 0;
stack <pair <int,int> > st;
vector <int> adj[N];

void dfs (int u,int pa) {
    low[u] = num[u] = ++num[0];
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v != pa) {
            if (num[v])
                low[u] = min(low[u],num[v]);
            else {
                st.push({u,v});
                dfs(v,u);
                low[u] = min(low[u],low[v]);
                if (low[v] >= num[u]) {
                    ans++;
                    pair <int,int> k;
                    do {
                        k = st.top();
                        st.pop();
                    } while (k != pair <int,int> {u,v});
                }
            }
        }
    }
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
        if (!num[i])
            dfs(i,i);

    cout << max(ans,1);
    return 0;
}

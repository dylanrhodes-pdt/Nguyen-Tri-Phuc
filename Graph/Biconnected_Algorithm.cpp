#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n,m,cnt;
vector<int> adj[N];
int Low[N],Visited[N],Parent[N],LastComponent[N];
stack<int> st;
int ComponentCount,Answer = 1;

bool cmin (int &a,int b) {
    if (a > b)
        a = b;
    else
        return false;
    return true;
}

bool cmax (int &a,int b) {
    if (a < b)
        a = b;
    else
        return false;
    return true;
}

void dfs (int u) {
    Low[u] = Visited[u] = ++cnt;

    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (Visited[v])
            cmin(Low[u],Visited[v]);
        else {
            st.push(u);
            Parent[v] = u;
            dfs(v);
            cmin (Low[u],Low[v]);
            if (Low[v] >= Visited[u]) {
                int Current = 0;
                ComponentCount++;
                do {
                    v = st.top();
                    st.pop();
                    if (cmax (LastComponent[v],ComponentCount))
                        Current++;
                } while (u != v);
                cmax (Answer,Current);
            }
        }
    }
    st.push(u);
}

main() {
    ios :: sync_with_stdio(false),cin.tie(0),cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
        adj[i].push_back(0);
    for (int i = 1; i <= n; ++i)
        if (!Visited[i])
            dfs(i);
    cout << Answer << endl;
}

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <array>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;

#define ri(a) dadsadasda=scanf("%d", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%d %d %d", &a, &b, &c)
#define rl(a) dadsadasda=scanf("%lld", &a)
#define rll(a,b) dadsadasda=scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
struct Dinic {
    int nodes, src, dst;
    vector<int> dist, q, work;
    struct edge {int to, rev; ll f, cap;};
    vector<vector<edge>> g;
    Dinic(int x): nodes(x), dist(x), q(x), work(x), g(x) {}
    void add_edge(int s, int t, ll cap) {
        g[s].pb((edge) {t, SZ(g[t]), 0, cap});
        g[t].pb((edge) {s, SZ(g[s]) - 1, 0, 0});
    }
    bool dinic_bfs() {
        fill(ALL(dist), -1); dist[src] = 0;
        int qt = 0; q[qt++] = src;
        for (int qh = 0; qh < qt; qh++) {
            int u = q[qh];
            FOR(i, 0, SZ(g[u])) {
                edge &e = g[u][i]; int v = g[u][i].to;
                if (dist[v] < 0 && e.f < e.cap)dist[v] = dist[u] + 1, q[qt++] = v;
            }
        }
        return dist[dst] >= 0;
    }
    ll dinic_dfs(int u, ll f) {
        if (u == dst)return f;
        for (int &i = work[u]; i < SZ(g[u]); i++) {
            edge &e = g[u][i];
            if (e.cap <= e.f)continue;
            int v = e.to;
            if (dist[v] == dist[u] + 1) {
                ll df = dinic_dfs(v, min(f, e.cap - e.f));
                if (df > 0) {e.f += df; g[v][e.rev].f -= df; return df;}
            }
        }
        return 0;
    }
    ll max_flow(int _src, int _dst) {
        src = _src; dst = _dst;
        ll result = 0;
        while (dinic_bfs()) {
            fill(ALL(work), 0);
            while (ll delta = dinic_dfs(src, INF))result += delta;
        }
        return result;
    }
};


int main() {
    int n; ri(n);
    Dinic mxf(n + 2);
    mxf.add_edge(0, 1, INF);
    FOR(i, 1, n + 1) {
        string aux;
        cin >> aux;
        if (aux[0] == '*') {
            int j; ri(j);
            if (j == 1)
                mxf.add_edge(i, n + 1, INF);
            else
                mxf.add_edge(i, j, INF);
        }
        else {
            int m = stoi(aux);
            FOR(_, 0, m) {
                int j; ri(j);
                if (j == 1)
                    mxf.add_edge(i, n + 1, 1);
                else
                    mxf.add_edge(i, j, 1);
            }
        }
    }

    ll flow = mxf.max_flow(0, n + 1);
    if (flow == INF)
        printf("*\n");
    else
        printf("%lld\n", flow + 1);

    return 0;
}
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

using namespace std;

typedef long long ll;
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
const int MAXN = 6e5; // CAMBIAR ESTE

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];

vi G[MAXN];
int IN[MAXN], OUT[MAXN], T;
void dfs(int x, int f = -1) {
    IN[x] = T++;
    for (auto y : G[x]) {
        if (y == f) continue;
        dfs(y, x);
    }
    OUT[x] = T;
}



struct STN {
    int t[2] = { -2, -1}; // t[0] = last time fill, t[1] = last time empty
    void merge(STN& L, STN& R) {
        FOR(i, 0, 2) t[i] = max(L.t[i], R.t[i]);
    }
};
STN ST[4 * MAXN];
ll lzy[4 * MAXN];
// Actualiza el nodo y guarda en lazy
void upd(int id, int l, int r, ll x) {
    lzy[id] = x;
    ST[id].t[0] = x;
}
// Propaga el update en lazy
void shift(int id, int l, int r) {
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    upd(L, l, m, lzy[id]);
    upd(R, m, r, lzy[id]);
    lzy[id] = 0;
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
    if (x == l && y == r) return ST[id];
    if (lzy[id] != 0)
        shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int x, int y, int v, int id = 1, int l = 0, int r = N) {
    if (x >= r || y <= l) return;
    if (x <= l && y >= r) {
        upd(id, l, r, v);
        return;
    }
    if (lzy[id] != 0)
        shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STU(x, y, v, L, l, m);
    STU(x, y, v, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
void STU2(int x, int y, int v, int id = 1, int l = 0, int r = N) {
    if (x >= r || y <= l) return;
    if (x <= l && y >= r) {
        ST[id].t[1] = v;
        return;
    }
    if (lzy[id] != 0)
        shift(id, l, r);
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STU2(x, y, v, L, l, m);
    STU2(x, y, v, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

int main() {
    ri(N);
    FOR(i, 1, N) {
        int a, b; rii(a, b); --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(0);
    int M; ri(M);
    FOR(i, 1, M + 1) {
        int c, v; rii(c, v); --v;
        if (c == 1) STU(IN[v], OUT[v], i);
        if (c == 2) STU2(IN[v], IN[v] + 1, i);
        if (c == 3) {
            int empty_t = STQ(IN[v], OUT[v]).t[1];
            int fill_t = STQ(IN[v], IN[v] + 1).t[0];
            if (empty_t >= fill_t) printf("0\n");
            else printf("1\n");
        }
    }

    return 0;
}
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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
struct POINT {
    ll x, v;

    bool operator<(POINT &b) {
        return x < b.x;
    }
};
POINT P[MAXN];
ll vs[MAXN];

void compress(int n) {
    sort(vs, vs + n);
    map<int, int> new_v;
    FOR(i, 0, n) {
        new_v[vs[i]] = i;
    }
    FOR(i, 0, n) {
        P[i].v = new_v[P[i].v];
    }
}

// Todos los rangos son semi-abiertos [a,b)
int N;
struct STN {
    ll sum, cnt;
    void merge(STN& L, STN& R) {
        sum = L.sum + R.sum;
        cnt = L.cnt + R.cnt;
    }
};
STN ST[4 * MAXN];
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
    if (x == l && y == r) return ST[id];
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (x >= m) return STQ(x, y, R, m, r);
    if (y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int p, ll x, int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id].sum += x;
        ST[id].cnt++;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

int main() {
    int n; ri(n);
    FOR(i, 0, n) {
        rl(P[i].x);
    }
    FOR(i, 0, n) {
        rl(P[i].v);
        vs[i] = P[i].v;
    }
    compress(n);
    sort(P, P + n);
    N = n;
    ll ans = 0;
    FOR(i, 0, n) {
        auto node = STQ(0, P[i].v + 1);
        ans += node.cnt * P[i].x - node.sum;
        STU(P[i].v, P[i].x);
    }
    printf("%lld\n", ans); 
    return 0;
}
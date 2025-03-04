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
#include <random>
#include <chrono>

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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, S;
struct STN {
    ll mn;
    void merge(STN& L, STN& R) {
        mn = min(L.mn, R.mn);
    }
    void operator=(ll a) {
        mn = a;
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
        ST[id] = x;
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    if (p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}


void solve() {
    rii(N, S);
    ll acum = 0;
    FOR(i, 0, N) {
        int a; ri(a);
        acum += a;
        STU(i, acum);
    }
    int l = 0, len = 0;
    FOR(i, 0, N) {
        int lo = 0, hi = N - i;
        ll prev = (i > 0 ? STQ(i - 1, i).mn : 0);
        while (lo < hi) {
            int mi = lo + (hi - lo + 1) / 2;
            ll aux = STQ(i, i + mi).mn - prev;
            if (-aux <= 1ll * S)
                lo = mi;
            else
                hi = mi - 1;
        }
        //printf("%d %d %lld\n", i, lo, prev);
        if (lo > len) {
            l = i;
            len = lo;
        }
    }
    if (len == 0)
        printf("-1\n");
    else
        printf("%d %d\n", l + 1, l + len);
}


int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}
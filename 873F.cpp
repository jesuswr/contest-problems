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
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
// * construccion O(n*ASZ)
// * cada camino representa un substring
// * para calcular cuantas veces sale cada substring, inicalmente marcamos cnt = 1 en todos los nodos (no clonados)
// y finalmente hacemos d[ d[v].link ].cnt += d[v]. cnt, en orden desde los caminos mas largos
// * para ver la cantidad de palabras diferentes seria un dp de cuantos caminos hay

struct SUF_AUT {
    static const int ASZ = 26;
    struct node { int len, link; array<int, ASZ> to; int cnt = 0;};
    vector<node> d = {{}};
    int last;
    void init(string S, string T) {
        last = d[0].len = 0;
        d[0].link = -1;
        d[0].to.fill(0);
        FOR(i, 0, SZ(S)) {
            int c = S[i] - 'a', v = SZ(d), p = last; // Be careful with mapping char to int
            d.emplace_back();
            d[v].len = d[last].len + 1;
            d[v].cnt = (T[i] == '0');
            for (; p > -1 && !d[p].to[c]; p = d[p].link)
                d[p].to[c] = v;
            if (p == -1) {
                d[v].link = 0;
            }
            else {
                int q = d[p].to[c];
                if (d[p].len + 1 == d[q].len) {
                    d[v].link = q;
                }
                else {
                    int qq = SZ(d);
                    d.emplace_back();
                    d[qq].len = d[p].len + 1;
                    d[qq].to = d[q].to;
                    d[qq].cnt = 0;
                    d[qq].link = d[q].link;
                    d[v].link = d[q].link = qq;
                    for (; p > -1 && d[p].to[c] == q; p = d[p].link)
                        d[p].to[c] = qq;
                }
            }
            last = v;
        }

        vii ord;
        FOR(i, 0, SZ(d)) ord.pb({d[i].len, i});
        sort(ALL(ord)); reverse(ALL(ord));
        for (auto [_, i] : ord) if (d[i].link != -1)
                d[d[i].link].cnt += d[i].cnt;

        ll ans = 0;
        FOR(i, 0, SZ(d)) ans = max(ans, 1ll * d[i].len * d[i].cnt);
        printf("%lld\n", ans);
    }
};


int main() {
    int n; ri(n);
    string s, t;
    cin >> s >> t;
    SUF_AUT sa;
    sa.init(s, t);
    return 0;
}
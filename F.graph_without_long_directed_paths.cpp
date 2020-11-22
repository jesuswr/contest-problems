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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
vi G[MAXN];
pii edges[MAXN];
int ans[MAXN];
bool vis[MAXN];
int col[MAXN];

void dfs(int x) {
    vis[x] = true;
    for (auto y : G[x]) {
        if (!vis[y]) {
            col[y] = 1 - col[x];
            dfs(y);
        }
        else if (col[x] == col[y]) {
            printf("NO\n");
            exit(0);
        }
    }
}

int main() {
    int n, m;
    rii(n, m);
    FOR(i, 0, m) {
        int a, b; rii(a, b); a--, b--;
        G[a].pb(b);
        G[b].pb(a);
        edges[i] = {a, b};
    }

    dfs(0);

    printf("YES\n");
    FOR(i, 0, m) {
        int a = edges[i].F;
        if (col[a] == 0)
            printf("0");
        else
            printf("1");
    } printf("\n");
    return 0;
}
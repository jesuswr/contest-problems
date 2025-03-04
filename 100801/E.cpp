#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i=n; i<(int)m; i++)
#define ROF(i,n,m) for(int i=n; i>(int)m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ri(a) scanf("%d",&a)
#define rii(a,b) ri(a),ri(b)
#define riii(a,b,c) rii(a,b),ri(c)
#define lri(a) scanf("%lld",&a)
#define lrii(a,b) lri(a),lri(b)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define debug true
#define dprintf debug && printf

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

char s[MAXN];
char t[MAXN];
int cnt[30];

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    // freopen("concatenation.in", "r", stdin);
    // freopen("concatenation.out", "w", stdout);

    scanf("%s", s);
    scanf("%s", t);
    int n = strlen(s);
    int m = strlen(t);

    FOR(i, 0, m - 1) cnt[t[i] - 'a']++;
    ll ans = 0;
    FOR(i, 0, n) {
        ans += m;
        if (i + 1 < n)
            ans -= cnt[s[i + 1] - 'a'];
    }

    printf("%lld\n", ans);

    return 0;
}

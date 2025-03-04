#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dsadsa;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dsadsa = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dsadsa = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	int n, m, k;
	rii(n, m), ri(k);
	int need_free = 2;
	vi a(k);
	FOR(i, 0, k) ri(a[i]);
	map<int, int> ind;
	FOR(i, 0, k) ind[a[i]] = i;

	int cnt = 0;
	int ci = -1;
	for (int i = k; i >= 1; --i) {
		ci = max(ci, ind[i]);
		if (ci - cnt > n * m - 2 - need_free) {
			printf("TIDAK\n");
			return;
		}
		++cnt;
	}
	printf("YA\n");
}

int main() {
	int t; ri(t);
	while (t--) solve();

	return 0;
}
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

void go(int nx, int ny, int x, int y) {
	int p = 1;
	bool first = true;
	while (nx--) {
		FOR(_, 0, x) printf("%d ", p);
		p += x + first;
		first = false;
	}
	while (ny--) {
		FOR(_, 0, y) printf("%d ", p);
		p += y + first;
		first = false;
	}
	printf("\n");
}

void solve() {
	int n, x, y; rii(n, x), ri(y);
	if (x > 0 && y > 0) {
		printf("-1\n");
		return;
	}

	if (x > 0 && ((n - 1) % x == 0)) {
		go((n - 1) / x, 0, x, 0);
		return;
	}
	swap(x, y);
	if (x > 0 && ((n - 1) % x == 0)) {
		go((n - 1) / x, 0, x, 0);
		return;
	}
	printf("-1\n");
}

int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}
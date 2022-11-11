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
	int n; ri(n);
	vi a(n);
	vi ans;
	FOR(i, 0, n) ri(a[i]);

	int msk = 0;
	FOR(i, 0, min(n, 42)) {
		int mxi = -1;
		FOR(i, 0, n) {
			if (a[i] == -1) continue;
			if (mxi == -1) {
				mxi = i;
				continue;
			}

			if ( ((~msk) & a[mxi]) < ((~msk) & a[i]) ) mxi = i;
		}
		ans.pb(a[mxi]);
		msk |= a[mxi];
		a[mxi] = -1;
	}
	FOR(i, 0, n) if (a[i] != -1) ans.pb(a[i]);
	FOR(i, 0, n) printf("%d ", ans[i]);
	printf("\n");

}


int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}
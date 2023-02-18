#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dasdas;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dasdas=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


void solve() {
	int n, m, d; 
	rii(n, m), ri(d);
	vi where(n+1);
	FOR(i,0,n) {
		int a; ri(a);
		where[a] = i;
	}
	vi b(m);
	FOR(i,0,m) ri(b[i]);

	int ans = INF;
	FOR(i,0,m-1) {
		if (where[b[i+1]] < where[b[i]]) ans = 0;
		else if (where[b[i+1]] > where[b[i]] + d) ans = 0;
		else {
			ans = min(ans, where[b[i+1]] - where[b[i]]);
			if (d < n - 1) ans = min(ans, d - (where[b[i+1]] - where[b[i]]) + 1);
		}
	}

	cout << ans << endl;
}


int main(){
	int t; ri(t);
	while(t--) {
		solve();
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int v[5] = {4,6,8,12,20};

int main(){
	int mn = 0;
	int mx = 0;
	FOR(i,0,5) {
		int a; cin >> a;
		mx += a * v[i];
		mn += a;
	}
	vi ans;
	while(mn <= mx) {
		ans.pb(mn);
		if (mn != mx) ans.pb(mx);
		mn++;
		mx--;
	}
	reverse(all(ans));
	for(int x : ans) cout << x << ' ';
	cout << endl;
	return 0;
}

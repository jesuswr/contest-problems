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

ll R;
string S;
int CNT[30];

ll binpow(ll b, ll e) {
	ll r = 1;
	while(e) {
		if (e&1) r = (r*b) % MOD;
		e >>= 1;
		b = (b * b) % MOD;
	}
	return r;
}

int main(){
	cin >> S;
	cin >> R;
	R %= MOD;

	int ans = 0;
	for(char c : S) {
		int C = c - 'a';
		CNT[C]++;
		int sm = 0;
		FOR(i,C+1,30) sm += CNT[i];
		ll aux = R * (R+1) % MOD;
		ans = (ans + aux * sm) % MOD;
	}
	FOR(i,0,30) CNT[i] = 0;
	reverse(all(S));
	for(char c : S) {
		int C = c - 'a';
		CNT[C]++;
		int sm = 0;
		FOR(i,C+1,30) sm += CNT[i];
		ll aux = R * (R-1) % MOD;
		ans = (ans + aux * sm) % MOD;
	}

	cout << ans * binpow(2, MOD-2) % MOD << endl;

	return 0;
}

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

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


int main(){
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		bool g = 0;
		FOR(i,1,11) FOR(j,i+1,11) {
			if (g) continue;
			int k = n - i - j;
			if (k <= 0 || k % 3 == 0 || i % 3 == 0 || j % 3 == 0 || i == k || k == j) continue;
			cout << "YES" << endl << i << " " << j << " " << k << endl;
			g = 1;
		}
		if (!g) cout << "NO" << endl;
	}
	return 0;
}

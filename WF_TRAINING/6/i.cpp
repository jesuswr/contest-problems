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


int N;
ll DP[MAXN][2];
ll A[MAXN];
ll f(int p, int z) {
	if (DP[p][z] != -1) return DP[p][z];
	if (p == N) return DP[p][z] = 0;
	if (p + 1 == N) return DP[p][z] = z ? 0 : INFLL;
	if (z) {
		return DP[p][z] = min({
			f(p+2, 0) + A[p+1],
			f(p+1, 0),
			f(p+1, 1) + A[p+1]
		});
	}
	else {
		return DP[p][z] = min({
			f(p+2, 0) + max(A[p], A[p+1]),
			f(p+1, 0) + A[p],
			f(p+1, 1) + max(A[p], A[p+1])
		});
	}
}


int main(){
	ri(N);
	FOR(i,0,N) lri(A[i]);
	FOR(i,0,N+1) DP[i][0] = DP[i][1] = -1;
	cout << f(0, 0) << endl;
	return 0;
}
